/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:05 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 11:13:04 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	*create_philosopher(int num, t_memory *memory)
{
	t_philosopher	*phil;

	phil = malloc(sizeof(t_philosopher));
	phil->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phil->fork_mutex, NULL);
	phil->last_meal_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phil->last_meal_mutex, NULL);
	phil->num = num + 1;
	phil->times_eaten = 0;
	phil->memory = memory;
	phil->last_meal = phil->memory->start_time;
	return (phil);
}

int	join_threads(t_memory *memory)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = memory->philosophers;
	while (i < memory->num_philo)
	{
		if (pthread_join(philosopher->fork, NULL) != 0)
		{
			ft_putstr_fd("Thread join failed\n", 2);
			return (0);
		}
		philosopher = philosopher->next;
		i++;
	}
	return (1);
}

void	create_threads(t_memory *memory)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = memory->philosophers;
	pthread_mutex_lock(memory->threads_created_mutex);
	pthread_create(&memory->overseer_thread, NULL, &overseer, memory);
	while (i < memory->num_philo)
	{
		if (pthread_create(&philosopher->fork, NULL, \
			&philo_process, philosopher) != 0)
		{
			ft_putstr_fd("Thread creation failed\n", 2);
			return ;
		}
		philosopher = philosopher->next;
		i++;
	}
	pthread_mutex_unlock(memory->threads_created_mutex);
	if (join_threads(memory) == 0)
		return ;
	pthread_join(memory->overseer_thread, NULL);
}

void	create_philosophers(t_memory *memory)
{
	int				i;
	t_philosopher	*first;
	t_philosopher	*current;
	t_philosopher	*temp;

	i = 0;
	first = create_philosopher(i++, memory);
	current = first;
	while (i < memory->num_philo)
	{
		temp = create_philosopher(i, memory);
		current->next = temp;
		temp->prev = current;
		current = temp;
		i++;
	}
	current->next = first;
	first->prev = current;
	memory->philosophers = first;
	create_threads(memory);
}
