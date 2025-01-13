/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:15 by sopperma         ###   ########.fr       */
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

void	destroy_fork_mutexes(t_memory *memory)
{
	int	i;

	i = 0;
	while (i < memory->num_philo)
	{
		pthread_mutex_destroy(&memory->forks[i]);
		i++;
	}
}

int	free_memory_variables(t_memory *memory, int location)
{
	if (location == 1 || location == 2 || location == 3)
		pthread_mutex_destroy(memory->status);
	if (location == 2 || location == 3)
		pthread_mutex_destroy(memory->print_mutex);
	if (location == 3)
		pthread_mutex_destroy(memory->last_meal_mutex);
	if (memory->status)
		free(memory->status);
	if (memory->print_mutex)
		free(memory->print_mutex);
	if (memory->last_meal_mutex)
		free(memory->last_meal_mutex);
	if (location == 4)
		destroy_fork_mutexes(memory);
	free_allocs(memory);
	return (0);
}

int	free_allocs(t_memory *memory)
{
	if (memory->philosopher_threads)
		free(memory->philosopher_threads);
	if (memory->philosophers)
		free(memory->philosophers);
	if (memory->forks)
		free(memory->forks);
	return (0);
}
