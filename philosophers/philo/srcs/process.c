/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:34 by sopperma          #+#    #+#             */
/*   Updated: 2024/12/17 17:57:41 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_event(t_philosopher *phil, char event)
{
	pthread_mutex_lock(phil->memory->print_mutex);
	if (event == DEAD)
		printf("%d %d died\n", get_current_time(phil), phil->num);
	if (check_sim_end(phil) == 0)
	{
		pthread_mutex_unlock(phil->memory->print_mutex);
		return (0);
	}
	if (event == FORK)
		printf("%d %d has taken a fork\n", get_current_time(phil), phil->num);
	if (event == EATING)
		printf("%d %d is eating\n", get_current_time(phil), phil->num);
	else if (event == SLEEPING)
		printf("%d %d is sleeping\n", get_current_time(phil), phil->num);
	else if (event == THINKING)
		printf("%d %d is thinking\n", get_current_time(phil), phil->num);
	pthread_mutex_unlock(phil->memory->print_mutex);
	return (1);
}

int	philosopher_starved(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->memory->last_meal_mutex);
	if (get_current_time(philosopher) - philosopher->last_meal >= \
		philosopher->memory->t_death)
	{
		pthread_mutex_lock(philosopher->memory->status);
		philosopher->memory->died = 1;
		philosopher->memory->dead_philosopher = philosopher->num;
		pthread_mutex_unlock(philosopher->memory->status);
		pthread_mutex_unlock(philosopher->memory->last_meal_mutex);
		print_event(philosopher, DEAD);
		return (0);
	}
	pthread_mutex_unlock(philosopher->memory->last_meal_mutex);
	return (1);
}

int	core_process(t_philosopher *philosopher, int *i)
{
	if (is_odd(philosopher->num))
	{
		if (eats(philosopher) == 0 || \
			sleeps(philosopher) == 0 || \
			print_event(philosopher, THINKING) == 0)
			return (0);
		if (*i < 1 && is_odd(philosopher->memory->num_philo))
		{
			my_usleep(philosopher->memory->t_eat / 2, philosopher);
		}
	}
	else
	{
		if (print_event(philosopher, THINKING) == 0)
			return (0);
		if (*i == 0)
		{
			my_usleep(philosopher->memory->t_eat, philosopher);
			*i += 1;
		}
		if (eats(philosopher) == 0 || \
			sleeps(philosopher) == 0)
			return (0);
	}
	return (1);
}

void	*philo_process(void *philosopher)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	philo = (t_philosopher *)philosopher;
	if (philo->memory->num_philo == 1)
		if (single_philo_process(philo) == 0)
			return (NULL);
	if (is_odd(philo->num) && philo->num == philo->memory->num_philo)
		print_event(philo, THINKING);
	while (1)
	{
		if (core_process(philo, &i) == 0)
			return (NULL);
	}
	return (NULL);
}
