/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/08 18:20:40 by sopperma         ###   ########.fr       */
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
    if (event == DEAD)
        printf("%d %d is dead\n", get_current_time(phil), phil->num);
    if (event == FULL)
        printf("All philosophers ate %d times\n", phil->memory->max_meals);
    
    pthread_mutex_lock(phil->memory->died_mutex);
    if (phil->memory->died == 1)
    {
        pthread_mutex_unlock(phil->memory->died_mutex);
        pthread_mutex_unlock(phil->memory->print_mutex);
        return (0);
    }
    pthread_mutex_unlock(phil->memory->died_mutex);

    pthread_mutex_lock(phil->memory->all_full_mutex);
        if(phil->memory->all_full == 1)
        {
            pthread_mutex_unlock(phil->memory->all_full_mutex);
            pthread_mutex_unlock(phil->memory->print_mutex);
            return (0);
        }
    pthread_mutex_unlock(phil->memory->all_full_mutex);

        // printf("%d %d is eating, ate %d times\n",get_current_time(phil) ,phil->num, phil->times_eaten + 1);
    
    if (event == EATING)
        printf("%d %d is eating\n",get_current_time(phil) ,phil->num);
    else if (event == SLEEPING)
        printf("%d %d is sleeping\n",get_current_time(phil), phil->num);
    else if (event == THINKING)    
        printf("%d %d is thinking\n", get_current_time(phil), phil->num);
    pthread_mutex_unlock(phil->memory->print_mutex);
    return (1);
}

int eats(t_philosopher *phil)
{
    pthread_mutex_lock(phil->fork_mutex);
    pthread_mutex_lock(phil->next->fork_mutex);
    if (print_event(phil, EATING) == 0)
    {
        pthread_mutex_unlock(phil->next->fork_mutex);
        pthread_mutex_unlock(phil->fork_mutex);
        return (0);
    }
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
    if (phil->memory->full_philosophers == phil->memory->num_philo)
    {
        pthread_mutex_lock(phil->memory->all_full_mutex);
        phil->memory->all_full = 1;
        pthread_mutex_unlock(phil->memory->all_full_mutex);
        // print_event(phil, FULL);
        pthread_mutex_unlock(phil->memory->full_mutex);
        return (0);
    }
    pthread_mutex_unlock(phil->memory->full_mutex);
    return (1);
}

int sleeps(t_philosopher *phil)
{
    if (print_event(phil, SLEEPING) == 0)
        return (0);
    my_usleep(phil->memory->t_sleep, phil);
    return (1);
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
            pthread_mutex_lock(philosopher->memory->all_full_mutex);
            if (philosopher->memory->all_full == 0)
            {
                pthread_mutex_unlock(philosopher->memory->all_full_mutex);
                pthread_mutex_unlock(philosopher->last_meal_mutex);
                print_event(philosopher, DEAD);
                return(NULL);
            }
            pthread_mutex_unlock(philosopher->memory->all_full_mutex);
            pthread_mutex_unlock(philosopher->last_meal_mutex);
            return(NULL);
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
        // if (is_odd(philo->memory->num_philo))
        // {
            if(is_odd(philo->num))
            {
                if (eats(philosopher) == 0 || sleeps(philosopher) == 0 || print_event(philosopher, THINKING) == 0)
                    return (NULL);
                my_usleep(philo->memory->t_eat, philo);
            }
            else
            {
                if (print_event(philosopher, THINKING) == 0)
                    return (NULL);
                my_usleep(philo->memory->t_eat, philo);
                if (eats(philosopher) == 0 || sleeps(philosopher) == 0)
                    return (NULL);
            }
        // }
        // else
        // {
        //     if(is_odd(philo->num))
        //     {
        //         if (eats(philosopher) == 0 || sleeps(philosopher) == 0 || print_event(philosopher, THINKING) == 0)
        //             return (NULL);
        //         my_usleep(philo->memory->t_eat - philo->memory->t_sleep, philo);
        //     }
        //     else
        //     {
        //         if (print_event(philosopher, THINKING) == 0)
        //             return (NULL);
        //         my_usleep(philo->memory->t_eat - philo->memory->t_sleep, philo);
        //         if (eats(philosopher) == 0 || sleeps(philosopher) == 0)
        //             return (NULL);
        //     }
        // }
    return (NULL);
    }
}