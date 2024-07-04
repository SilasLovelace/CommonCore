/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/04 15:27:02 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits_recieved bits_recieved;

int decrypt(int *bits, int size)
{
    int res = 0;
    int i = 0;
    while(i < size)
        res = res << 1 | bits[i++];
    return (res);
}

void signal_handler(int signum, siginfo_t *info, void *data)
{
    (void)data;
    (void)info;
    (void)signum;
    if(signum == SIGUSR1)
    {
        bits_recieved.bit[bits_recieved.current] = 1;
        bits_recieved.current++;
        // write (1, "1", 1);
    }
    else if(signum == SIGUSR2)
    {
        bits_recieved.bit[bits_recieved.current] = 0;
        bits_recieved.current++;
        // write (1, "0", 1);
    }
    if (bits_recieved.current == 32)
    {
        // int i = 0;
        // while (i < bits_recieved.current)
        // {
        //    ft_putnbr_fd(decrypt(bits_recieved.bit, 32), 1);
        //    i+=32;
        // }
        
        bits_recieved.size = decrypt(bits_recieved.bit, 32);
        free(bits_recieved.bit);
        bits_recieved.bit = malloc(sizeof(int) * (bits_recieved.size));
        write (1, "\n", 1);
        ft_putnbr_fd(bits_recieved.size, 1);
        write (1, "\n", 1);
    }
    if (bits_recieved.current > 32 && bits_recieved.current % 8 == 0)
    {
        ft_putchar_fd( (char)decrypt((bits_recieved.bit + bits_recieved.current -8 ), 8),1);
    }
    if (bits_recieved.current == bits_recieved.size )
    {
        bits_recieved.current = 0;
        free(bits_recieved.bit);
        bits_recieved.bit = malloc(sizeof(int) * 32);
    }
    kill(info->si_pid, SIGUSR1);
}

#include <signal.h>

int main(void)
{
    __pid_t server_pid;
    // int     new_string = 1;
    server_pid = getpid();
    ft_printf("The server-process ID is %d\n", server_pid);

    struct sigaction action;
    ft_bzero(&action, sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_handler;

    bits_recieved.bit = malloc(sizeof(int) * 32);
    
    if (sigaction(SIGUSR1, &action, NULL) == -1 \
        || sigaction(SIGUSR2, &action, NULL) == -1)
    {
        perror("sigaction");
        return (1);
    }
    while (1)
    {
        pause();
    }
 return (0);
}