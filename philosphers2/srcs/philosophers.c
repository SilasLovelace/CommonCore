/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:23 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/23 16:04:35 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	initialze_memory(t_memory *memory, int ac, char **av)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	memory->start_time = ((long long)time.tv_sec * 1000) \
		+ ((long long)time.tv_usec / 1000);
	memory->num_philo = ft_atoi(av[1]);
	memory->t_death = ft_atoi(av[2]);
	memory->t_eat = ft_atoi(av[3]);
	memory->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		memory->max_meals = ft_atoi(av[5]);
	//protect here
	memory->status = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->status, NULL);
	memory->print_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->print_mutex, NULL);
	memory->last_meal_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->last_meal_mutex, NULL);
	//
	if (create_philosophers(memory) == 0)
		return (cleanup(memory));
	return (1);
}

int	free_error(int error)
{
	if (error == ARGUMENT_OVERFLOW)
		ft_putstr_fd("Error: Argument overflows!\n", 2);
	if (error == PHILO_NUM_ERROR)
		ft_putstr_fd \
			("Error: There must be at least 1 and max 200 philosophers\n", 2);
	if (error == PHILO_EAT_ERROR)
		ft_putstr_fd("Error: Number of meals must be at least 1\n", 2);
	if (error == PHILO_TIME_ERROR)
		ft_putstr_fd("Error: Time must be at least 60ms\n", 2);
	return (0);
}

int	check_inputs(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(ft_itoa(ft_atoi(av[i])), \
			av[i], ft_strlen(av[i])) != 0)
			return (free_error(ARGUMENT_OVERFLOW));
		i++;
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (free_error(PHILO_NUM_ERROR));
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (free_error(PHILO_EAT_ERROR));
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (free_error(PHILO_TIME_ERROR));
	return (1);
}

int allocate_arrays(t_memory *memory)
{
	
	memory->philosophers = malloc(sizeof(t_philosopher) * memory->num_philo);
	if (memory->philosophers == NULL)
		return free_allocs(memory);
	memory->philosopher_threads = malloc(sizeof(pthread_t) * memory->num_philo);
	if (memory->philosopher_threads == NULL)
		return free_allocs(memory);
	memory->forks = malloc(sizeof(pthread_mutex_t) * memory->num_philo);
	if (memory->forks == NULL)
		return free_allocs(memory);
	return (1);
}

int	main(int ac, char **av)
{
	t_memory	*memory;
	
	if (check_inputs(ac, av) == 0)
		return (0);
	memory = malloc(sizeof(t_memory));
	ft_bzero(memory, sizeof(t_memory));
	if (allocate_arrays(memory) == 0)
		return (0);
	if (ac == 5 || ac == 6)
	{	
		if (initialze_memory(memory, ac, av) == 0)
			return (0);
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (0);
	}
	// cleanup working?
	// cleanup(memory);
	return (0);
}
