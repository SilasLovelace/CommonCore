/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:12:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/05 10:25:44 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, int signum, t_bits *g_bits)
{
	int	i;

	i = 0;
	if (signum == SIGUSR1)
		i = kill(pid, SIGUSR1);
	else if (signum == SIGUSR2)
		i = kill(pid, SIGUSR2);
	if (i == -1)
	{
		free(g_bits->bit);
		write(1, "Error sending signal!\n", 22);
		exit (0);
	}
}
