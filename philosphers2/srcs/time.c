/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:32:51 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 11:06:02 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_usleep(long time, t_philosopher *philosopher)
{
	long	start;

	start = get_current_time(philosopher);
	while (get_current_time(philosopher) - start < time)
	{
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

int	check_sim_end(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->memory->status);
	if (philosopher->memory->died == 1)
	{
		pthread_mutex_unlock(philosopher->memory->status);
		return (0);
	}
	if (philosopher->memory->full_philosophers == philosopher->memory->num_philo)
	{
		pthread_mutex_unlock(philosopher->memory->status);
		return (0);
	}
	pthread_mutex_unlock(philosopher->memory->status);
	return (1);
}
