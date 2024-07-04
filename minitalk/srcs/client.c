/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:04 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/04 16:53:44 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits bits;

int static  *encrypt(int input, int size)
{
    int     *e_bit;
    int     i;
    int     x;
    
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

void static signal_handler (int signum, siginfo_t *info, void *data)
{
    (void)data;
    bits.current += 1;
    if (signum == SIGUSR1)
    {
        if(bits.bit[bits.current] == 1)
            kill(info->si_pid, SIGUSR1);
        else if(bits.bit[bits.current] == 0)
            kill(info->si_pid, SIGUSR2);  
    }
    else if (signum == SIGUSR2)
    {
        free(bits.bit);
        exit(1);
    }
}

int static encode_size ()
{
    int    *e_bits;
    
    e_bits = encrypt(bits.size, 32);
    if (!e_bits)
        return (0);
    while (bits.encoded_bits < 32)
    {
        bits.bit[bits.encoded_bits] = e_bits[bits.encoded_bits];
        bits.encoded_bits++;
    }
    free(e_bits);
    return (1);
}

int static encode_string (char *string)
{
    int     x;
    int     i;
    int    *e_bits;
    
    i = 0;
    while (string[i])
    {
        x = 0;
        e_bits = encrypt(string[i], 8);
        if (!e_bits)
            return (0);
        while (x < 8)
        {
            bits.bit[bits.encoded_bits] = e_bits[x];
            bits.encoded_bits++;
            x++;
        }
        free(e_bits);
        i++;
    }
    return(1);
}

int main(int ac, char* av[])
{
    if (ac == 3)
    {  
        __pid_t server_pid;
        server_pid = ft_atoi(av[1]);
        bits.bit = malloc(sizeof(int) * ((ft_strlen(av[2]) * 8) + 32));
        if (!bits.bit)
            return (0);
        bits.size = (ft_strlen(av[2]) * 8) + 32;
        struct sigaction action;
        ft_bzero(&action, sizeof(action));
        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = signal_handler;
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        if (!encode_size() || !encode_string(av[2]))
            return(free(bits.bit), 0);
        if(bits.bit[bits.current] == 1)
            kill(server_pid, SIGUSR1);
        else if(bits.bit[bits.current] == 0)
            kill(server_pid, SIGUSR2);
        while (1)
            pause();
    }
    return 0;
}
