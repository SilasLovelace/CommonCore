/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:37 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 10:56:27 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void print_philosophers(t_memory *memory)
// {
// 	t_philosopher *philosopher;
// 	int i = 0;

// 	philosopher = memory->philosophers;
// 	while (i < memory->num_philo)
// 	{
// 		printf("Phil Num: %d\n", philosopher->num);
// 		philosopher = philosopher->next;
// 		i++;
// 	}
// }
// void print_memory(t_memory *memory)
// {
// 	printf("Number of philosophers: %d\n", memory->num_philo);
// 	printf("Time to die: %d\n", memory->t_death);
// 	printf("Time to eat: %d\n", memory->t_eat);
// 	printf("Time to sleep: %d\n", memory->t_sleep);
// 	printf("Max meals: %d\n", memory->max_meals);
// 	printf("Start time: %lld\n", memory->start_time);
// 	print_philosophers(memory);
// }

int	is_odd(int i)
{
	return (i % 2);
}

void	lock_forks(t_philosopher *phil)
{
	if (is_odd(phil->num))
	{
		pthread_mutex_lock(phil->fork_mutex);
		print_event(phil, FORK);
		pthread_mutex_lock(phil->next->fork_mutex);
		print_event(phil, FORK);
	}
	else
	{
		pthread_mutex_lock(phil->next->fork_mutex);
		print_event(phil, FORK);
		pthread_mutex_lock(phil->fork_mutex);
		print_event(phil, FORK);
	}
}

void	unlock_forks(t_philosopher *phil)
{
	if (is_odd(phil->num))
	{
		pthread_mutex_unlock(phil->next->fork_mutex);
		pthread_mutex_unlock(phil->fork_mutex);
	}
	else
	{
		pthread_mutex_unlock(phil->fork_mutex);
		pthread_mutex_unlock(phil->next->fork_mutex);
	}
}

void	*single_philo_process(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->fork_mutex);
	print_event(philosopher, FORK);
	my_usleep(philosopher->memory->t_death, philosopher);
	pthread_mutex_unlock(philosopher->fork_mutex);
	print_event(philosopher, DEAD);
	pthread_mutex_lock(philosopher->memory->died_mutex);
	philosopher->memory->died = 1;
	pthread_mutex_unlock(philosopher->memory->died_mutex);
	return (NULL);
}
