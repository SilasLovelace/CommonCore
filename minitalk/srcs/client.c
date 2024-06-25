/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:04 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/25 18:18:57 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// CLIENT.C file

/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/

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
        ft_printf("%d", e_char[x]);
        x++;
    }
    ft_printf("\n");
    return (e_char);
}
int main(int ac, char* av[])
{
    __pid_t server_pid;
    int    *e_char;
    int     i;
    int     x;
    i = 0;

    (void)ac;
    server_pid= ft_atoi(av[1]);
    while (av[2][i])
    {
        x = 0;
        e_char = encrypt_char(av[2][i]);
        while (x < 8)
        {
            printf("sending %d -> %d to %d\n", x, e_char[x], server_pid);
            
            if (e_char[x] == 1)
                kill(server_pid, SIGUSR1);
            else if (e_char[x] == 0)
                kill(server_pid, SIGUSR2);
            x++;
        }
        free(e_char);
        i++;
        usleep(1000);
    }
    
  return 0;
}
