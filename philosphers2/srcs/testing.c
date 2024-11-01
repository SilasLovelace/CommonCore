/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:37 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 10:50:14 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_odd(int i)
{
	return (i % 2);
}

void	lock_forks(t_philosopher *phil)
{
	if (is_odd(phil->num))
	{
		pthread_mutex_lock(phil->l_fork_mutex);
		print_event(phil, FORK);
		pthread_mutex_lock(phil->r_fork_mutex);
		print_event(phil, FORK);
	}
	else
	{
		pthread_mutex_lock(phil->r_fork_mutex);
		print_event(phil, FORK);
		pthread_mutex_lock(phil->l_fork_mutex);
		print_event(phil, FORK);
	}
}

void	unlock_forks(t_philosopher *phil)
{
	if (is_odd(phil->num))
	{
		pthread_mutex_unlock(phil->r_fork_mutex);
		pthread_mutex_unlock(phil->l_fork_mutex);
	}
	else
	{
		pthread_mutex_unlock(phil->l_fork_mutex);
		pthread_mutex_unlock(phil->r_fork_mutex);
	}
}

int	single_philo_process(t_philosopher *philosopher)
{
	print_event(philosopher, THINKING);
	pthread_mutex_lock(philosopher->l_fork_mutex);
	print_event(philosopher, FORK);
	my_usleep(philosopher->memory->t_death, philosopher);
	pthread_mutex_unlock(philosopher->l_fork_mutex);
	print_event(philosopher, DEAD);
	pthread_mutex_lock(philosopher->memory->status);
	philosopher->memory->died = 1;
	pthread_mutex_unlock(philosopher->memory->status);
	return (0);
}
