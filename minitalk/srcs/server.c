/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/26 18:59:33 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int bitcount = 0;

int decrypt(int* bits, int size)
{
    int c;
    int    x;

    x = 0;
    c = 0;
    while(x < size)
        c = c << 1 | bits[x++];
    // write(1, &c, 1);
    return (c);
}

void signal_char(int signum, siginfo_t *info, void *data)
{
    (void)data;
    (void)info;
    static int bits[8];
    char c = '0';
    // write(1, "test\n", 5);

    // char c = '0' + bitcount;
    
    // write(1, "bit", 3);
    // write(1, &c, 1);
    // write(1, "\n", 1);

    
    if (signum == SIGUSR1)
    {
     c += 1;   
        bits[bitcount] = 1;
    }
    else if (signum == SIGUSR2)
    {
     c += 0;     
        bits[bitcount] = 0;
    }
    write(1, &c, 1);
    bitcount++;
    if (bitcount == 8)
    {
        bitcount = 0;
        decrypt(bits, 8);
        write(1, "\n", 1);
        // write(1, "out\n", 4);
    }

    // kill(SIGUSR1, info->si_pid);
}

int signal_int(int signum)
{
    static int bits[32];
  
    if (signum == SIGUSR1)
        bits[bitcount] = 1;
    else if (signum == SIGUSR2)
        bits[bitcount] = 0;
    bitcount++;
    if (bitcount == 32)
    {
        bitcount = 0;
        return decrypt(bits, 32);  
    }
    return (-1);
}

void signal_handler(int signum, siginfo_t *info, void *data)
{
    (void)data;
    (void)info;
    (void)signum;
    // write(1, "test\n", 5);
    // // printf("Signal %d received, value = %d\n", signum, info->si_value.sival_int);
    // printf("PID %d\n", info->si_pid);
    kill(info->si_pid, SIGUSR1);
    if(signum == SIGUSR1)
        write (1, "1", 1);
    else if(signum == SIGUSR2)
        write (1, "0", 1);
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
    
    if (sigaction(SIGUSR1, &action, NULL) == -1 \
        || sigaction(SIGUSR2, &action, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }
    while (1)
    {
        pause();
    }
 return (0);
}