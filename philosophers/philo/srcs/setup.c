/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:05 by sopperma          #+#    #+#             */
/*   Updated: 2024/12/17 18:10:51 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_basic_values(t_memory *memory, int ac, char **av)
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
}

int	join_threads(t_memory *memory)
{
	int				i;

	i = 0;
	while (i < memory->num_philo)
	{
		if (pthread_join(memory->philosopher_threads[i], NULL) != 0)
		{
			ft_putstr_fd("Thread join failed\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_threads(t_memory *memory)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	while (i < memory->num_philo)
	{
		philosopher = &memory->philosophers[i];
		if (pthread_create(&memory->philosopher_threads[i], NULL, \
			&philo_process, philosopher) != 0)
		{
			ft_putstr_fd("Thread creation failed\n", 2);
			while (--i >= 0)
				pthread_join(memory->philosopher_threads[i], NULL);
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_philosophers(t_memory *memory)
{
	int				i;

	i = 0;
	while (i < memory->num_philo)
	{
		memory->philosophers[i].l_fork_mutex = &memory->forks[i];
		memory->philosophers[i].r_fork_mutex = \
			&memory->forks[(i + 1) % memory->num_philo];
		memory->philosophers[i].num = i + 1;
		memory->philosophers[i].times_eaten = 0;
		memory->philosophers[i].memory = memory;
		memory->philosophers[i].last_meal = 0;
		i++;
	}
	if (create_threads(memory) == 0)
		return (0);
	return (1);
}
