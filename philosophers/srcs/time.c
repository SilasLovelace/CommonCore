/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:32:51 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 10:57:24 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_usleep(long time, t_philosopher *philosopher)
{
	long	start;

	start = get_current_time(philosopher);
	while (get_current_time(philosopher) - start < time)
	{
		pthread_mutex_lock(philosopher->last_meal_mutex);
		if (get_current_time(philosopher) - philosopher->last_meal > \
			philosopher->memory->t_death)
		{
			pthread_mutex_lock(philosopher->memory->died_mutex);
			philosopher->memory->died = 1;
			philosopher->memory->dead_philosopher = philosopher->num;
			pthread_mutex_unlock(philosopher->memory->died_mutex);
			pthread_mutex_unlock(philosopher->last_meal_mutex);
			print_event(philosopher, DEAD);
			return ;
		}
		pthread_mutex_unlock(philosopher->last_meal_mutex);
		if (check_sim_end(philosopher) == 0)
			return ;
		usleep(100);
	}
}

int	get_current_time(t_philosopher *phil)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((long long)time.tv_sec * 1000) + \
		((long long)time.tv_usec / 1000) - phil->memory->start_time);
}

int	check_sim_end(t_philosopher *philospher)
{
	pthread_mutex_lock(philospher->memory->died_mutex);
	if (philospher->memory->died == 1)
	{
		pthread_mutex_unlock(philospher->memory->died_mutex);
		return (0);
	}
	pthread_mutex_unlock(philospher->memory->died_mutex);
	pthread_mutex_lock(philospher->memory->all_full_mutex);
	if (philospher->memory->all_full == 1)
	{
		pthread_mutex_unlock(philospher->memory->all_full_mutex);
		return (0);
	}
	pthread_mutex_unlock(philospher->memory->all_full_mutex);
	return (1);
}
