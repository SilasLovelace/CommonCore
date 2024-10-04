/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/26 14:30:34 by sopperma         ###   ########.fr       */
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

    pthread_mutex_lock(phil->is_eating_mutex);
    phil->is_eating = 1;
    pthread_mutex_lock(phil->memory->print);
    printf("%d %d->is eating, ate %d times\n",get_current_time(phil) ,phil->num, phil->times_eaten + 1);
    usleep(phil->memory->t_eat * 1000);
    
    pthread_mutex_unlock(phil->next->mutex); 
    pthread_mutex_unlock(phil->mutex);
    
    pthread_mutex_lock(phil->memory->full);
    phil->is_eating = 0;
    if (phil->times_eaten < phil->memory->max_meals)
        phil->times_eaten++;
    if (phil->times_eaten >= phil->memory->max_meals)
        phil->memory->full_philosophers++;
    pthread_mutex_unlock(phil->memory->full);
    pthread_mutex_unlock(phil->is_eating_mutex);

    pthread_mutex_lock(phil->memory->get_time);
    phil->last_eat_time = get_current_time(phil);
    pthread_mutex_unlock(phil->memory->get_time);
    pthread_mutex_unlock(phil->memory->print);
}

void sleeps(t_philosopher *phil)
{
    pthread_mutex_lock(phil->memory->print);
    printf("%d %d->is sleeping\n",get_current_time(phil), phil->num);
    pthread_mutex_unlock(phil->memory->print);
    usleep(phil->memory->t_sleep * 1000);
}

void *do_something(void *philosopher)
{
    t_philosopher *philo = (t_philosopher *)philosopher;
    

    while (1)
    {
        pthread_mutex_lock(philo->memory->death);
        if (philo->memory->died == 1)
        {
            pthread_mutex_lock(philo->memory->print);
            printf("Philosopher is dead\n");
            pthread_mutex_unlock(philo->memory->print);
        }        
        pthread_mutex_unlock(philo->memory->death);
        if(is_odd(philo->num))
        {
            eats(philosopher);
            sleeps(philosopher);
            pthread_mutex_lock(philo->memory->print);
            printf("%d %d->is thinking\n", get_current_time(philo), philo->num);
            pthread_mutex_unlock(philo->memory->print); 
            usleep(philo->memory->t_eat * 1000);
        }
        else
        {
            pthread_mutex_lock(philo->memory->print);
            printf("%d %d->is thinking\n", get_current_time(philo), philo->num);
            pthread_mutex_unlock(philo->memory->print); 
            usleep(philo->memory->t_eat * 1000);
            eats(philo);
            sleeps(philo); 
        }
    }
    return (philosopher);
}