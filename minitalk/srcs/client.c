/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   client.c								 :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: sopperma <sopperma@student.42.fr>	  +#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2024/07/04 16:57:58 by sopperma		#+#  #+#		  */
/*   Updated: 2024/07/04 16:59:39 by sopperma	   ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits	g_bits;

int static	*encrypt(int input, int size)
{
	int	*e_bit;
	int	i;
	int	x;

	i = size - 1;
	x = 0;
	e_bit = malloc(sizeof(int) * size);
	if (!e_bit)
		return (NULL);
	while (x < size)
	{
		e_bit[x] = (input >> i) & 1;
		i--;
		x++;
	}
	return (e_bit);
}

void static	signal_handler(int signum, siginfo_t *info, void *data)
{
	(void)data;
	g_bits.current += 1;
	if (signum == SIGUSR1)
	{
		if (g_bits.bit[g_bits.current] == 1)
			send_signal(info->si_pid, SIGUSR1, &g_bits);
		else if (g_bits.bit[g_bits.current] == 0)
			send_signal(info->si_pid, SIGUSR2, &g_bits);
	}
	else if (signum == SIGUSR2)
	{
		free(g_bits.bit);
		exit(1);
	}
}

int static	encode_size(void)
{
	int	*e_bits;

	e_bits = encrypt(g_bits.size, 32);
	if (!e_bits)
		return (0);
	while (g_bits.encoded_bits < 32)
	{
		g_bits.bit[g_bits.encoded_bits] = e_bits[g_bits.encoded_bits];
		g_bits.encoded_bits++;
	}
	free(e_bits);
	return (1);
}

int static	encode_string(char *string)
{
	int	x;
	int	i;
	int	*e_bits;

	i = 0;
	while (string[i])
	{
		x = 0;
		e_bits = encrypt(string[i], 8);
		if (!e_bits)
			return (0);
		while (x < 8)
		{
			g_bits.bit[g_bits.encoded_bits] = e_bits[x];
			g_bits.encoded_bits++;
			x++;
		}
		free(e_bits);
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	__pid_t				server_pid;
	struct sigaction	action;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		g_bits.bit = malloc(sizeof(int) * ((ft_strlen(av[2]) * 8) + 32));
		if (!g_bits.bit)
			return (0);
		g_bits.size = (ft_strlen(av[2]) * 8) + 32;
		ft_bzero(&action, sizeof(action));
		action.sa_flags = SA_SIGINFO;
		action.sa_sigaction = signal_handler;
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		if (!encode_size() || !encode_string(av[2]))
			return (free(g_bits.bit), 0);
		if (g_bits.bit[g_bits.current] == 1)
			send_signal(server_pid, SIGUSR1, &g_bits);
		else if (g_bits.bit[g_bits.current] == 0)
			send_signal(server_pid, SIGUSR2, &g_bits);
		while (1)
			pause();
	}
	return (0);
}
