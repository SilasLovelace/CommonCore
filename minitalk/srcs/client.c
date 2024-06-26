/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:04 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/26 19:11:09 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits bits;

int    *encrypt_char(char msg)
{
    int     *e_char;
    int     i;
    int     x;
    
    i = 7;
    x = 0;
    e_char = malloc(sizeof(int) * 8);
    if (!e_char)
        return (NULL);
    while (x < 8)
    {
        e_char[x] = (msg >> i) & 1;
        i--;
        // ft_printf("%d", e_char[x]);
        x++;
    }
    // ft_printf("\n");
    return (e_char);
}


void  signal_handler (int signum, siginfo_t *info, void *data)
{
    (void)info;
    (void)data;
    (void)signum;
    write (1, "rec\n", 4);
    bits.current += 1;
    if(!(bits.current >= bits.size))
    {
        if(bits.bit[bits.current] == 1)
            kill(info->si_pid, SIGUSR1);
        else if(bits.bit[bits.current] == 0)
            kill(info->si_pid, SIGUSR2);  
    }
}

int main(int ac, char* av[])
{
    (void)ac;
    __pid_t server_pid;
    server_pid = ft_atoi(av[1]);
    int    *e_char;
    int     i;
    int     x;
    i = 0;

    
    bits.bit = malloc(sizeof(int) * (ft_strlen(av[2]) + 1) * 8);
    int bit = 0;
    bits.size = ft_strlen(av[2])* 8;
    
    struct sigaction action;
    ft_bzero(&action, sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &action, NULL);
    // sigaction(SIGUSR2, &action, NULL);

    while (av[2][i])
    {
        x = 0;
        e_char = encrypt_char(av[2][i]);
        while (x < 8)
        {
            // printf("sending %d -> %d to %d\n", x, e_char[x], server_pid);
            if (e_char[x] == 1)
            {
                bits.bit[bit] = 1;
                printf("1");  
            }
            else if (e_char[x] == 0)
            {
                bits.bit[bit] = 0;
                printf("0");   
            } 
            bit++;
            x++;
        }
        printf("\n");
        free(e_char);
        i++;
    }
   /*  int f = 0;
    while (f < bit)
    {
        printf("%d", bits.bit[f++]);
    } */
    if(bits.bit[bits.current] == 1)
        kill(server_pid, SIGUSR1);
    else if(bits.bit[bits.current] == 0)
        kill(server_pid, SIGUSR2);
    while (1)
    {
        pause();
    }
  return 0;
}
