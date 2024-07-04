/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:55:14 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:51 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits_recieved	g_bits_recieved;

int static	decrypt(int *bits, int size)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
		res = res << 1 | bits[i++];
	return (res);
}

int static	print_string(siginfo_t *info)
{
	int	i;

	i = 32;
	while (i < g_bits_recieved.size)
	{
		ft_putchar_fd((char)decrypt((g_bits_recieved.bit + i), 8), 1);
		i += 8;
	}
	g_bits_recieved.current = 0;
	free(g_bits_recieved.bit);
	kill(info->si_pid, SIGUSR2);
	return (1);
}

void static	signal_handler(int signum, siginfo_t *info, void *data)
{
	(void)data;
	if (g_bits_recieved.current == 0)
	{
		g_bits_recieved.bit = malloc(sizeof(int) * 32);
		if (!g_bits_recieved.bit)
			exit(0);
	}
	if (signum == SIGUSR1)
		g_bits_recieved.bit[g_bits_recieved.current++] = 1;
	else if (signum == SIGUSR2)
		g_bits_recieved.bit[g_bits_recieved.current++] = 0;
	if (g_bits_recieved.current == 32)
	{
		g_bits_recieved.size = decrypt(g_bits_recieved.bit, 32);
		free(g_bits_recieved.bit);
		g_bits_recieved.bit = malloc(sizeof(int) * (g_bits_recieved.size));
		if (!g_bits_recieved.bit)
			exit(0);
	}
	if (g_bits_recieved.current == g_bits_recieved.size)
	{
		print_string(info);
		return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	__pid_t				server_pid;
	struct sigaction	action;

	server_pid = getpid();
	ft_printf("The server-process ID is %d\n", server_pid);
	ft_bzero(&action, sizeof(action));
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
