/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/25 18:21:43 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int bitcount = 0;

void decrypt(int* bits)
{
    char c;
    int    x;

    x = 0;
    c = 0;
    while(x < 8)
        c = c << 1 | bits[x++];
    printf("%c", c);
}

void signal_handler(int signum)
{
    (void)signum;
    // static int bits[8];
    // printf("recieved %d", signum);

    // ft_printf("%d\n", signum == SIGUSR1 ? 1 : 0);
    printf("test");
    //  printf("recieved %d -> %d", bitcount, signum == SIGUSR1);
    // if (signum == SIGUSR1)
    // {
    //     printf("recieved %d -> %d", bitcount, signum == SIGUSR1 ? 1 : 0);
    // }
    //     // bits[bitcount] = 1;
    // else if (signum == SIGUSR2)
    // {
    //     printf("recieved %d -> %d", bitcount, signum == SIGUSR1 ? 1 : 0);
    // }
        // bits[bitcount] = 0;
    // bitcount++;
    // if (bitcount == 8)
    // {
    //     decrypt(bits);  
    //     bitcount = 0;
    // }
}

int main(void)
{
    __pid_t server_pid;
    
    server_pid = getpid();
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    ft_printf("The server-process ID is %d\n", server_pid);
    
    while (1)
    {
        pause();
    }
 return (0);
}