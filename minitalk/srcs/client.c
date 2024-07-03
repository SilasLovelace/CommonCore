/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:04 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/03 18:58:07 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits bits;

int    *encrypt(char input, int size)
{
    int     *e_char;
    int     i;
    int     x;
    
    i = size - 1;
    x = 0;
    e_char = malloc(sizeof(int) * size);
    if (!e_char)
        return (NULL);
    while (x < size)
    {
        e_char[x] = (input >> i) & 1;
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
    // write (1, "rec\n", 4);
    bits.current += 1;
    if(!(bits.current >= bits.size))
    {
        if(bits.bit[bits.current] == 1)
            kill(info->si_pid, SIGUSR1);
        else if(bits.bit[bits.current] == 0)
            kill(info->si_pid, SIGUSR2);  
    }
    else
    {
        exit(1);
    }
}

int main(int ac, char* av[])
{
    (void)ac;
    __pid_t server_pid;
    server_pid = ft_atoi(av[1]);
    int    *e_bits;
    int     i;
    int     x;
    i = 0;

    
    bits.bit = malloc(sizeof(int) * ((ft_strlen(av[2]) * 8) + 32));
    int bit = 0;
    bits.size = (ft_strlen(av[2]) * 8) + 32;
    
    struct sigaction action;
    ft_bzero(&action, sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &action, NULL);
    // sigaction(SIGUSR2, &action, NULL);

    x = 0;
    e_bits = encrypt(bits.size, 32);
    while (x < 32)
    {
        // printf("sending %d -> %d to %d\n", x, e_char[x], server_pid);
        if (e_bits[x] == 1)
        {
            bits.bit[bit] = 1;
            printf("1");  
        }
        else if (e_bits[x] == 0)
        {
            bits.bit[bit] = 0;
            printf("0");   
        } 
        bit++;
        x++;
    }
    free(e_bits);
    printf("\n");
    while (av[2][i])
    {
        x = 0;
        e_bits = encrypt(av[2][i], 8);
        while (x < 8)
        {
            // printf("sending %d -> %d to %d\n", x, e_char[x], server_pid);
            if (e_bits[x] == 1)
            {
                bits.bit[bit] = 1;
                printf("1");  
            }
            else if (e_bits[x] == 0)
            {
                bits.bit[bit] = 0;
                printf("0");   
            } 
            bit++;
            x++;
        }
        printf("\n");
        free(e_bits);
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
