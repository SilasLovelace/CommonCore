/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:05 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/23 16:07:22 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int destroy_prev_mutex(t_memory *memory, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&memory->forks[i]);
		i++;
	}
	return (0);
}

int create_philosopher(int num, t_memory *memory)
{
	t_philosopher	*phil;
	
	phil = &memory->philosophers[num];
	if (pthread_mutex_init(&memory->forks[num], NULL))
		return (destroy_prev_mutex(memory, num));
	phil->l_fork_mutex = &memory->forks[num];
	phil->r_fork_mutex = &memory->forks[(num + 1) % memory->num_philo];
	phil->num = num + 1;
	phil->times_eaten = 0;
	phil->memory = memory;
	phil->last_meal = phil->memory->start_time;
	return (1);
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
	t_philosopher	philosopher;
	int				i;

	i = 0;
	// pthread_mutex_lock(memory->threads_created_mutex);
	// pthread_create(&memory->overseer_thread, NULL, &overseer, memory);
	while (i < memory->num_philo)
	{
		philosopher = memory->philosophers[i];
		if (pthread_create(&memory->philosopher_threads[i], NULL, \
			&philo_process, &philosopher) != 0)
		{
			ft_putstr_fd("Thread creation failed\n", 2);
			while (--i >= 0)
				pthread_join(memory->philosopher_threads[i], NULL);
			return (0);
		}
		i++;
	}
	// pthread_mutex_unlock(memory->threads_created_mutex);
	if (join_threads(memory) != 0)
		return (0);
	// pthread_join(memory->overseer_thread, NULL);
	return (1);
}

int	create_philosophers(t_memory *memory)
{
	int				i;

	i = 0;
	while (i < memory->num_philo)
	{
		if (create_philosopher(i, memory) == 0)
			return (0);
		i++;
	}
	if (create_threads(memory) == 0)
		return (0);
	return (1);
}
