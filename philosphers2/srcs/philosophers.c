/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:23 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 11:21:59 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_prev_mutex(t_memory *memory, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&memory->forks[i]);
		i++;
	}
	return (0);
}

int	create_forks(t_memory *memory)
{
	int	i;

	i = 0;
	while (i < memory->num_philo)
	{
		if (pthread_mutex_init(&memory->forks[i], NULL) != 0)
			return (destroy_prev_mutex(memory, i));
		i++;
	}
	return (1);
}

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
	memory->status = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->status, NULL);
	memory->print_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->print_mutex, NULL);
	memory->last_meal_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(memory->last_meal_mutex, NULL);
	if (create_forks(memory) == 0)
		return (cleanup(memory));
	if (create_philosophers(memory) == 0)
		return (cleanup(memory));
	return (1);
}

int	main(int ac, char **av)
{
	t_memory	*memory;

	if (ac == 5 || ac == 6)
	{
		if (check_inputs(ac, av) == 0)
			return (0);
		memory = malloc(sizeof(t_memory));
		ft_bzero(memory, sizeof(t_memory));
		memory->num_philo = ft_atoi(av[1]);
		if (allocate_arrays(memory) == 0)
			return (0);
		if (initialze_memory(memory, ac, av) == 0)
			return (0);
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (0);
	}
	return (0);
}
