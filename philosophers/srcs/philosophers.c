/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:23 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/16 13:09:25 by sopperma         ###   ########.fr       */
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
	memory->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->print_mutex, NULL);
	memory->died_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->died_mutex, NULL);
	memory->full_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->full_mutex, NULL);
	memory->all_full_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->all_full_mutex, NULL);
	memory->threads_created_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->threads_created_mutex, NULL);
	create_philosophers(memory);
}

int free_error(t_memory *memory, int error)
{
	if(error == ARGUMENT_OVERFLOW)
		ft_putstr_fd("Error: Argument overflows!\n", 2);
	if (error == PHILO_NUM_ERROR)
		ft_putstr_fd("Error: There must be at least 1 and max 200 philosophers\n", 2);
	if (error == PHILO_EAT_ERROR)
		ft_putstr_fd("Error: Number of meals must be at least 1\n", 2);
	if (error == PHILO_TIME_ERROR)
		ft_putstr_fd("Error: Time must be at least 60ms\n", 2);
	free(memory);
	return (0);
}

int main (int ac, char **av)
{

	t_memory *memory;
	int i = 1;
		
	memory = malloc(sizeof(t_memory));
	ft_bzero(memory, sizeof(t_memory));
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if(ft_strncmp(ft_itoa(ft_atoi(av[i])), av[i], ft_strlen(av[i])) !=0 )
				return(free_error(memory, ARGUMENT_OVERFLOW));
			i++;
		}
		if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
			return(free_error(memory, PHILO_NUM_ERROR));
		if (ac == 6 && ft_atoi(av[5]) < 1)
			return(free_error(memory, PHILO_EAT_ERROR));
		if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
			return(free_error(memory, PHILO_TIME_ERROR));
		initialze_memory(memory, ac, av);
		// print_memory(memory);
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	cleanup(memory);
	return (0);
}