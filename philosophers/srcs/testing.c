/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:52:29 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/25 15:58:42 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void print_philosophers(t_memory *memory)
{
    t_philosopher *philosopher;
    int i = 0;

    philosopher = memory->philosophers;
    while (i < memory->num_philo)
    {
        printf("Phil Num: %d\n", philosopher->num);
        philosopher = philosopher->next;
        i++;
    }
}
void print_memory(t_memory *memory)
{
    printf("Number of philosophers: %d\n", memory->num_philo);
    printf("Time to die: %d\n", memory->t_death);
    printf("Time to eat: %d\n", memory->t_eat);
    printf("Time to sleep: %d\n", memory->t_sleep);
    printf("Max meals: %d\n", memory->max_meals);
    printf("Start time: %lld\n", memory->start_time);
    print_philosophers(memory);
}