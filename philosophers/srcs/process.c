/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/12 14:22:38 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void do_something(t_params *params, t_memory *memory)
{
   int i = 0;

    while (i < params->num_philo)
    {
        memory->philosophers[i].num = i;
        memory->philosophers[i].is_eating = 0;
        memory->philosophers[i].is_dead = 0;
        memory->philosophers[i].is_full = 0;
        memory->philosophers[i].times_eaten = 0;
        // memory->philosophers[i].t_sleep = params->t_sleep;
        memory->philosophers[i].fork = 
        // memory->philosophers[i].r_fork = &memory->forks[(i + 1) % params->num_philo];
        i++;
    }
    // pthread_create(&memory, NULL, &function_for_algo, datastruct);
    // pthread_mutex_init(memory address (), NULL);
    // pthread_mutex_lock(memory address ());
    // pthread_mutex_unlock(memory address ());
}