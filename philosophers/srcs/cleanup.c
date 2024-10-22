/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 11:00:32 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy(t_memory *memory)
{
	pthread_mutex_destroy(memory->print_mutex);
	pthread_mutex_destroy(memory->died_mutex);
	pthread_mutex_destroy(memory->full_mutex);
	pthread_mutex_destroy(memory->all_full_mutex);
	pthread_mutex_destroy(memory->threads_created_mutex);
	free(memory->print_mutex);
	free(memory->died_mutex);
	free(memory->full_mutex);
	free(memory->all_full_mutex);
	free(memory->threads_created_mutex);
	free(memory);
}

void	cleanup(t_memory *memory)
{
	t_philosopher	*first_philosopher;
	t_philosopher	*current;
	t_philosopher	*next;

	first_philosopher = memory->philosophers;
	current = first_philosopher;
	while (current)
	{
		next = current->next;
		pthread_mutex_destroy(current->fork_mutex);
		pthread_mutex_destroy(current->last_meal_mutex);
		free(current->fork_mutex);
		free(current->last_meal_mutex);
		free(current);
		if (next == first_philosopher)
			break ;
		current = next;
	}
}
