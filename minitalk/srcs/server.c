/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/04 16:53:58 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits_recieved bits_recieved;

int static decrypt(int *bits, int size)
{
    int res = 0;
    int i = 0;
    while(i < size)
        res = res << 1 | bits[i++];
    return (res);
}

int static print_string(siginfo_t *info)
{
    int i;
    
    i = 32;
    while (i < bits_recieved.size)
    {
        ft_putchar_fd( (char)decrypt((bits_recieved.bit + i), 8),1);
        i += 8;
    }
    bits_recieved.current = 0;
    free(bits_recieved.bit);
    kill(info->si_pid, SIGUSR2);
    return (1);
}

void static signal_handler(int signum, siginfo_t *info, void *data)
{
    (void)data;
    if (bits_recieved.current == 0)
    {
        bits_recieved.bit = malloc(sizeof(int) * 32);
        if (!bits_recieved.bit)
            exit(0);
    }
    if (signum == SIGUSR1)
        bits_recieved.bit[bits_recieved.current++] = 1;
    else if (signum == SIGUSR2)
        bits_recieved.bit[bits_recieved.current++] = 0;
    if (bits_recieved.current == 32)
    {
        bits_recieved.size = decrypt(bits_recieved.bit, 32);
        free(bits_recieved.bit);
        bits_recieved.bit = malloc(sizeof(int) * (bits_recieved.size));
        if (!bits_recieved.bit)
            exit(0);
    }
    if (bits_recieved.current == bits_recieved.size )
    {
        print_string(info);
        return ;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    __pid_t server_pid;
    server_pid = getpid();
    ft_printf("The server-process ID is %d\n", server_pid);
    struct sigaction action;
    ft_bzero(&action, sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (1)
        pause();
    return (0);
}
