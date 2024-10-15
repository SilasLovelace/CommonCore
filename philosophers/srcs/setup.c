/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:01:46 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/15 14:33:53 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher *create_philosopher(int num, t_memory *memory)
{
    t_philosopher *philosopher;

    philosopher = malloc(sizeof(t_philosopher));
    philosopher->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)); 
    pthread_mutex_init(philosopher->fork_mutex, NULL);
    philosopher->last_meal_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(philosopher->last_meal_mutex, NULL);
    philosopher->num = num + 1;
    philosopher->times_eaten = 0;
    philosopher->memory = memory;
    philosopher->last_meal = philosopher->memory->start_time;
    return (philosopher);
}


void create_threads(t_memory *memory)
{
    t_philosopher *philosopher;
    int i = 0;

    philosopher = memory->philosophers;
    pthread_mutex_lock(memory->threads_created_mutex);
    pthread_create(&memory->overseer_thread, NULL, &overseer, memory);
    while (i < memory->num_philo)
    {
        if (pthread_create(&philosopher->fork, NULL, &philo_process, philosopher) != 0)
        {
            printf("Thread failed\n");   
            return ;
        }
        philosopher = philosopher->next;
        i++;
    }
    pthread_mutex_unlock(memory->threads_created_mutex);
    i=0;
    while (i < memory->num_philo)
    {
     if (pthread_join(philosopher->fork, NULL) != 0)
        {
            printf("Thread join failed\n");
            return;
        }
        philosopher = philosopher->next;
        i++;
    }
    pthread_join(memory->overseer_thread, NULL);
}

void create_philosophers(t_memory *memory)
{
    int i = 0;
    t_philosopher *first;
    t_philosopher *current;
    t_philosopher *temp;
    
    first = create_philosopher(i++, memory);
    current = first;

    while (i < memory->num_philo)
    {
        temp = create_philosopher(i, memory);
        current->next = temp;
        temp->prev = current;
        current = temp;
        i++;
    }
    current->next = first;
    first->prev = current;
    memory->philosophers = first;
    create_threads(memory);
}