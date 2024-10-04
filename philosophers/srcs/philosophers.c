/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:18:52 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/26 14:17:30 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void initialze_memory(t_memory *memory, int ac, char **av)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    memory->start_time = ((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000);
    
    memory->num_philo = ft_atoi(av[1]);
    memory->t_death = ft_atoi(av[2]);
    memory->t_eat = ft_atoi(av[3]);
    memory->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        memory->max_meals = ft_atoi(av[5]);
    memory->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(memory->print, NULL);
    memory->get_time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(memory->get_time, NULL);
    memory->death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(memory->death, NULL);
    memory->full = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(memory->full, NULL);
    create_philosophers(memory);
}

int main (int ac, char **av)
{

    t_memory *memory;
    
    memory = malloc(sizeof(t_memory));
    ft_bzero(memory, sizeof(t_memory));
    if (ac == 5 || ac == 6)
    {
        initialze_memory(memory, ac, av);
        // print_memory(memory);
    }
    else
    {
        ft_putstr_fd("Error: Invalid number of arguments\n", 2);
        return (1);
    }
    
    return (0);
}