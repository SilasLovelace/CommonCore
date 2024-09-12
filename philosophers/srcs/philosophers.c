/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:18:52 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/12 14:05:38 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int ac, char **av)
{
    t_params *params;
    time_t start_time;
    t_memory *memory;

    ft_bzero(&params, sizeof(t_params));
    ft_bzero(&memory, sizeof(t_memory));
    if (ac == 5 || ac == 6)
    {
        params->num_philo = ft_atoi(av[1]);
        params->t_death = ft_atoi(av[2]);
        params->t_eat = ft_atoi(av[3]);
        params->t_sleep = ft_atoi(av[4]);
        if (ac == 6)
            params->max_meals = ft_atoi(av[5]);
        params->start_time = time(NULL);
    }
    else
    {
        ft_putstr_fd("Error: Invalid number of arguments\n", 2);
        return (1);
    }
    do_something(params, memory);    
    
    return (0);
}