/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/25 16:39:27 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int get_current_time(t_philosopher *phil)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000) - phil->memory->start_time);
}

int is_odd(int i)
{
    return (i % 2);
}

void eats(t_philosopher *phil)
{
    pthread_mutex_lock(phil->mutex);
    pthread_mutex_lock(phil->next->mutex);
    pthread_mutex_lock(phil->memory->print);
    pthread_mutex_lock(phil->memory->get_time);
    printf("%d %d->is eating, ate %d times\n",get_current_time(phil) ,phil->num, phil->times_eaten + 1);
    phil->is_eating = 1;
    usleep(phil->memory->t_eat);
    phil->times_eaten++;
    phil->last_eat_time = get_current_time(phil);
    phil->is_eating = 0;
    pthread_mutex_unlock(phil->memory->get_time);
    pthread_mutex_unlock(phil->mutex);
    pthread_mutex_unlock(phil->next->mutex); 
    pthread_mutex_unlock(phil->memory->print);
}

void sleeps(t_philosopher *phil)
{
    pthread_mutex_lock(phil->memory->print);
    printf("%d %d->is sleeping\n",get_current_time(phil), phil->num);
    pthread_mutex_unlock(phil->memory->print);
    usleep(phil->memory->t_sleep);
}

void *do_something(void *philosopher)
{
    t_philosopher *philo = (t_philosopher *)philosopher;
    

    while (1)
    {
        if(is_odd(philo->num))
        {
            eats(philosopher);
            sleeps(philosopher);
        }
        else
        {
            pthread_mutex_lock(philo->memory->print);
            printf("%d %d->is thinking\n", get_current_time(philo), philo->num);
            pthread_mutex_unlock(philo->memory->print); 
            usleep(philo->memory->t_sleep);
            eats(philo);
            sleeps(philo); 
        }
    }
    return (philosopher);
}