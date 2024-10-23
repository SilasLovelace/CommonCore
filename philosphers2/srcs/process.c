/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:34 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/23 13:35:13 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_event(t_philosopher *phil, char event)
{
	pthread_mutex_lock(phil->memory->print_mutex);
	if (event == DEAD)
		printf("%d %d died\n", get_current_time(phil), phil->num);
	if (event == FULL)
		printf("All philosophers ate %d times\n", phil->memory->max_meals);
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

void	*kill_philosopher(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->memory->died_mutex);
	philosopher->memory->died = 1;
	philosopher->memory->dead_philosopher = philosopher->num;
	pthread_mutex_unlock(philosopher->memory->died_mutex);
	pthread_mutex_lock(philosopher->memory->all_full_mutex);
	if (philosopher->memory->all_full == 0)
	{
		pthread_mutex_unlock(philosopher->memory->all_full_mutex);
		pthread_mutex_unlock(philosopher->last_meal_mutex);
		print_event(philosopher, DEAD);
		return (NULL);
	}
	pthread_mutex_unlock(philosopher->memory->all_full_mutex);
	pthread_mutex_unlock(philosopher->last_meal_mutex);
	return (NULL);
}

void	*overseer(void *memory)
{
	t_memory		*mem;
	t_philosopher	*philosopher;

	mem = (t_memory *)memory;
	philosopher = mem->philosophers;
	pthread_mutex_lock(mem->threads_created_mutex);
	pthread_mutex_unlock(mem->threads_created_mutex);
	while (1)
	{
		pthread_mutex_lock(philosopher->last_meal_mutex);
		if (get_current_time(philosopher) - philosopher->last_meal \
			> mem->t_death)
			return (kill_philosopher(philosopher));
		pthread_mutex_unlock(philosopher->last_meal_mutex);
		pthread_mutex_lock(philosopher->memory->died_mutex);
		if (philosopher->memory->died == 1)
		{
			pthread_mutex_unlock(philosopher->memory->died_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philosopher->memory->died_mutex);
		philosopher = philosopher->next;
		usleep(10);
	}
}

int	core_process(t_philosopher *philosopher, int i)
{
	if (is_odd(philosopher->num))
	{
		if (eats(philosopher) == 0 || sleeps(philosopher) == 0 || \
			print_event(philosopher, THINKING) == 0)
			return (0);
	}
	else
	{
		if (print_event(philosopher, THINKING) == 0)
			return (0);
		if (i++ == 0)
			my_usleep(philosopher->memory->t_eat, philosopher);
		if (eats(philosopher) == 0 || sleeps(philosopher) == 0)
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
	pthread_mutex_lock(philo->memory->threads_created_mutex);
	pthread_mutex_unlock(philo->memory->threads_created_mutex);
	if (philo->memory->num_philo == 1)
		if (single_philo_process(philo) == 0)
			return (NULL);
	while (1)
		core_process(philo, i);
	return (NULL);
}
