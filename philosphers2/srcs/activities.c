/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:36:27 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/23 15:50:28 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eats(t_philosopher *phil)
{
	lock_forks(phil);
	if (print_event(phil, EATING) == 0)
	{
		unlock_forks(phil);
		return (0);
	}
	pthread_mutex_lock(phil->memory->last_meal_mutex);
	phil->last_meal = get_current_time(phil);
	pthread_mutex_unlock(phil->memory->last_meal_mutex);
	my_usleep(phil->memory->t_eat, phil);
	unlock_forks(phil);
	pthread_mutex_lock(phil->memory->status);
	phil->times_eaten++;
	if (phil->times_eaten == phil->memory->max_meals)
		phil->memory->full_philosophers++;
	pthread_mutex_unlock(phil->memory->status);
	return (check_sim_end(phil));
}

int	sleeps(t_philosopher *phil)
{
	if (print_event(phil, SLEEPING) == 0)
		return (0);
	my_usleep(phil->memory->t_sleep, phil);
	return (1);
}
