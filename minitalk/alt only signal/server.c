/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/26 16:24:23 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int bitcount = 0;

void decrypt(int* bits, int size)
{
    int c;
    int    x;

    // write (1, "dec\n", 4);
    x = 0;
    c = 0;
    while(x < size)
        c = c << 1 | bits[x++];
    write(1, &c, 1);
}

void signal_char(int signum)
{

    static int bits[8];
    // write (1, "t\n", 2);

    if (signum == SIGUSR1)
        bits[bitcount] = 1;
    else if (signum == SIGUSR2)
        bits[bitcount] = 0;
    bitcount++;
    if (bitcount == 8)
    {
        bitcount = 0;
        decrypt(bits, 8);  
    }
}


#include <signal.h>

int main(void)
{
    __pid_t server_pid;
    server_pid = getpid();
    ft_printf("The server-process ID is %d\n", server_pid);

    signal(SIGUSR1, signal_char); 
    signal(SIGUSR2, signal_char);

    while (1)
    {
        pause();
    }
 return (0);
}