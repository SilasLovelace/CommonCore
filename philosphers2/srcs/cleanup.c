/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 10:57:48 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	destroy(t_memory *memory)
// {
// 	pthread_mutex_destroy(memory->print_mutex);
// 	pthread_mutex_destroy(memory->died_mutex);
// 	pthread_mutex_destroy(memory->full_mutex);
// 	pthread_mutex_destroy(memory->all_full_mutex);
// 	pthread_mutex_destroy(memory->threads_created_mutex);
// 	free(memory->print_mutex);
// 	free(memory->died_mutex);
// 	free(memory->full_mutex);
// 	free(memory->all_full_mutex);
// 	free(memory->threads_created_mutex);
// 	free(memory);
// }

int free_memory(t_memory *memory)
{
	ft_putstr_fd("Freeing Memory\n", 2);
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

int	cleanup(t_memory *memory)
{
	ft_putstr_fd("Error: Memory allocation failed\n", 2);
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

int free_allocs(t_memory *memory)
{
	int i;

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
