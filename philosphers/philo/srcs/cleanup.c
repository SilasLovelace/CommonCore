/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/12/17 16:32:58 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	cleanup(t_memory *memory)
{
	pthread_mutex_destroy(memory->status);
	free(memory->status);
	pthread_mutex_destroy(memory->print_mutex);
	free(memory->print_mutex);
	pthread_mutex_destroy(memory->last_meal_mutex);
	free(memory->last_meal_mutex);
	free_allocs(memory);
	free(memory);
	return (0);
}

int	free_allocs(t_memory *memory)
{
	int	i;

	i = 0;
	if (memory->philosopher_threads)
		free(memory->philosopher_threads);
	if (memory->philosophers)
		free(memory->philosophers);
	if (memory->forks)
	{
		while (i < memory->num_philo)
		{
			pthread_mutex_destroy(&memory->forks[i]);
			i++;
		}
		free(memory->forks);
	}
	return (0);
}
