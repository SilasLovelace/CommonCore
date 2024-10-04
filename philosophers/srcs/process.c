/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/04 12:29:17 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int get_current_time(t_philosopher *phil)
{
    struct timeval time;
    gettimeofday(&time, NULL);

    return (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000) - phil->memory->start_time);
}

void    my_usleep(long time, t_philosopher *phil)
{
    long    start;

    start = get_current_time(phil);
    while (get_current_time(phil) - start < time)
    {
        usleep(100);
    }
}

int is_odd(int i)
{
    return (i % 2);
}

int print_event(t_philosopher *phil, char event)
{
    pthread_mutex_lock(phil->memory->print_mutex);
    
    pthread_mutex_lock(phil->memory->died_mutex);
    if (phil->memory->died == 1)
    {
        pthread_mutex_unlock(phil->memory->died_mutex);
        pthread_mutex_unlock(phil->memory->print_mutex);
        return (0);
    }
    pthread_mutex_unlock(phil->memory->died_mutex);

    pthread_mutex_lock(phil->memory->full_mutex);
    if (phil->memory->num_philo == phil->memory->full_philosophers)
    {
        pthread_mutex_unlock(phil->memory->full_mutex);
        pthread_mutex_unlock(phil->memory->print_mutex);
        return (0);
    }
    pthread_mutex_unlock(phil->memory->full_mutex);

    if (event == EATING)
        printf("%d %d is eating, ate %d times\n",get_current_time(phil) ,phil->num, phil->times_eaten + 1);
    else if (event == SLEEPING)
        printf("%d %d is sleeping\n",get_current_time(phil), phil->num);
    else if (event == THINKING)    
        printf("%d %d is thinking\n", get_current_time(phil), phil->num);

    
    else if (event == FULL)
        printf("All philosophers ate %d times\n", phil->memory->max_meals);
    else if (event == DEAD)
        printf("%d %d is dead\n", get_current_time(phil), phil->num);
    pthread_mutex_unlock(phil->memory->print_mutex);
    return (1);
}

void eats(t_philosopher *phil)
{
    pthread_mutex_lock(phil->fork_mutex);
    pthread_mutex_lock(phil->next->fork_mutex);
    print_event(phil, EATING);
    
    pthread_mutex_lock(phil->last_meal_mutex);
    phil->last_meal = get_current_time(phil);
    pthread_mutex_unlock(phil->last_meal_mutex);
    
    my_usleep(phil->memory->t_eat, phil);
    pthread_mutex_unlock(phil->next->fork_mutex); 
    pthread_mutex_unlock(phil->fork_mutex);
    
    pthread_mutex_lock(phil->memory->full_mutex);
    phil->times_eaten++;
    if (phil->times_eaten == phil->memory->max_meals)
        phil->memory->full_philosophers++;
    pthread_mutex_unlock(phil->memory->full_mutex);
}

void sleeps(t_philosopher *phil)
{
    print_event(phil, SLEEPING);
    my_usleep(phil->memory->t_sleep, phil);
}

void *overseer(void *memory)
{
    t_memory *mem = (t_memory *)memory;
    t_philosopher *philosopher;
    
    philosopher = mem->philosophers;
    while (1)
    {
        pthread_mutex_lock(philosopher->last_meal_mutex);
        if (get_current_time(philosopher) - philosopher->last_meal > mem->t_death)
        {
            pthread_mutex_lock(philosopher->memory->died_mutex);
            philosopher->memory->died = 1;
            pthread_mutex_unlock(philosopher->memory->died_mutex);

            print_event(philosopher, DEAD);
            return (NULL);
        }
        pthread_mutex_unlock(philosopher->last_meal_mutex);
        philosopher = philosopher->next;
    }
}

void *philo_process(void *philosopher)
{
    t_philosopher *philo = (t_philosopher *)philosopher;
    
    while (1)
    {
        // pthread_mutex_lock(philo->memory->full_mutex);
        // if (philo->memory->full_philosophers == philo->memory->num_philo)
        // {
        //     print_event(philo, FULL);
        //     pthread_mutex_unlock(philo->memory->full_mutex);
        //     break;
        // }
        // pthread_mutex_unlock(philo->memory->full_mutex);

        // pthread_mutex_lock(philo->last_meal_mutex);
        // if (get_current_time(philosopher) - philo->last_meal > philo->memory->t_death)
        // {
        //     pthread_mutex_lock(philo->memory->died_mutex);
        //     philo->memory->died = 1;
        //     pthread_mutex_unlock(philo->memory->died_mutex);
        //     print_event(philosopher, DEAD);
        //     break;
        // }
        // pthread_mutex_unlock(philo->last_meal_mutex);

        if(is_odd(philo->num))
        {
            eats(philosopher);
            sleeps(philosopher);
            print_event(philosopher, THINKING);
            my_usleep(philo->memory->t_eat, philo);
        }
        else
        {
            print_event(philosopher, THINKING);
            my_usleep(philo->memory->t_eat, philo);
            eats(philo);
            sleeps(philo); 
        }
    }
    return (NULL);
}