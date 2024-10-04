/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:01:46 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/26 14:32:01 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher *create_philosopher(int num, t_memory *memory)
{
    t_philosopher *philosopher;

    philosopher = malloc(sizeof(t_philosopher));
    philosopher->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)); 
    pthread_mutex_init(philosopher->mutex, NULL);
    philosopher->is_eating_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(philosopher->is_eating_mutex, NULL);
    philosopher->num = num;
    philosopher->memory = memory;
    return (philosopher);
}

void *overseer(void *memory)
{
    t_memory *mem = (t_memory *)memory;
    t_philosopher *philosopher;
    
    philosopher = mem->philosophers;
    while (1)
    {
        pthread_mutex_lock(mem->get_time);
        pthread_mutex_lock(philosopher->is_eating_mutex);
        if (philosopher->last_eat_time - get_current_time(philosopher) > mem->t_death && philosopher->is_eating == 0)
        {
            pthread_mutex_lock(mem->death);
            mem->died = 1;
            pthread_mutex_unlock(mem->death);
        }
        pthread_mutex_unlock(philosopher->is_eating_mutex);
        pthread_mutex_unlock(mem->get_time);
        
        pthread_mutex_lock(mem->full);
        if (mem->full_philosophers == mem->num_philo)
        {
            pthread_mutex_lock(mem->print);
            printf("All philosophers ate %d times\n", mem->max_meals);
            pthread_mutex_unlock(mem->print);
            exit(0);
        }
        pthread_mutex_unlock(mem->full);
        philosopher = philosopher->next;
        // usleep(10);
    }
}

void create_threads(t_memory *memory)
{
    t_philosopher *philosopher;
    int i = 0;

    philosopher = memory->philosophers;
    pthread_create(&memory->overseer_thread, NULL, &overseer, memory);
    // pthread_join(memory->overseer_thread, NULL);
    while (i < memory->num_philo)
    {
        if (pthread_create(&philosopher->p_thread, NULL, &do_something, philosopher) != 0)
        {
            printf("Thread failed\n");   
            return ;
        }
        philosopher = philosopher->next;
        i++;
    } 
    i=0;
    while (i < memory->num_philo)
    {
     if (pthread_join(philosopher->p_thread, NULL) != 0)
        {
            printf("Thread join failed\n");
            return;
        }
        philosopher = philosopher->next;
        i++;
    }
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