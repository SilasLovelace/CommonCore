/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:09:34 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/23 12:19:39 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int get_current_time(t_philosopher *phil)
{
	struct timeval time;
	gettimeofday(&time, NULL);

	return (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000) - phil->memory->start_time);
}
int check_sim_end(t_philosopher *philospher)
{
	pthread_mutex_lock(philospher->memory->died_mutex);
	if (philospher->memory->died == 1)
	{
		pthread_mutex_unlock(philospher->memory->died_mutex);
		return (0);
	}
	pthread_mutex_unlock(philospher->memory->died_mutex);

	pthread_mutex_lock(philospher->memory->all_full_mutex);
	if(philospher->memory->all_full == 1)
	{
		pthread_mutex_unlock(philospher->memory->all_full_mutex);
		return (0);
	}
	pthread_mutex_unlock(philospher->memory->all_full_mutex);
	return (1);
}
void	my_usleep(long time, t_philosopher *philosopher)
{
	long	start;

	start = get_current_time(philosopher);
	while (get_current_time(philosopher) - start < time)
	{
		// pthread_mutex_lock(philosopher->last_meal_mutex);
		// if (get_current_time(philosopher) - philosopher->last_meal > philosopher->memory->t_death)
		// {
		// 	pthread_mutex_lock(philosopher->memory->died_mutex);
		// 	philosopher->memory->died = 1;
		// 	philosopher->memory->dead_philosopher = philosopher->num;
		// 	pthread_mutex_unlock(philosopher->memory->died_mutex);
		// 	pthread_mutex_unlock(philosopher->last_meal_mutex);
		// 	print_event(philosopher, DEAD);
		// 	return ;
		// }
		// pthread_mutex_unlock(philosopher->last_meal_mutex);
		if (check_sim_end(philosopher) == 0)
			return ;
		usleep(100);
	}
}

int is_odd(int i)
{
	return (i % 2);
}

int print_event(t_philosopher *phil, char event)
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
		printf("%d %d is eating\n",get_current_time(phil) ,phil->num);
	else if (event == SLEEPING)
		printf("%d %d is sleeping\n",get_current_time(phil), phil->num);
	else if (event == THINKING) 
		printf("%d %d is thinking\n", get_current_time(phil), phil->num);
	pthread_mutex_unlock(phil->memory->print_mutex);
	return (1);
}

void lock_forks (t_philosopher *phil)
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

void unlock_forks (t_philosopher *phil)
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

int eats(t_philosopher *phil)
{
	lock_forks(phil);
	if (print_event(phil, EATING) == 0)
	{
		unlock_forks(phil);
		return (0);
	}
	pthread_mutex_lock(phil->last_meal_mutex);
	phil->last_meal = get_current_time(phil);
	pthread_mutex_unlock(phil->last_meal_mutex);
		
	my_usleep(phil->memory->t_eat, phil);
	unlock_forks(phil);
		
	pthread_mutex_lock(phil->memory->full_mutex);
	phil->times_eaten++;
	if (phil->times_eaten == phil->memory->max_meals)
		phil->memory->full_philosophers++;
	if (phil->memory->full_philosophers == phil->memory->num_philo)
	{
		pthread_mutex_lock(phil->memory->all_full_mutex);
		phil->memory->all_full = 1;
		pthread_mutex_unlock(phil->memory->all_full_mutex);
		pthread_mutex_unlock(phil->memory->full_mutex);
		return (0);
	}
	pthread_mutex_unlock(phil->memory->full_mutex);
	return (1);
}

int sleeps(t_philosopher *phil)
{
	if (print_event(phil, SLEEPING) == 0)
		return (0);
	my_usleep(phil->memory->t_sleep, phil);
	return (1);
}


void *overseer(void *memory)
{
	t_memory *mem = (t_memory *)memory;
	t_philosopher *philosopher;
		
	philosopher = mem->philosophers;
	pthread_mutex_lock(mem->threads_created_mutex);
	pthread_mutex_unlock(mem->threads_created_mutex);
	while (1)
	{
		pthread_mutex_lock(philosopher->last_meal_mutex);
		if (get_current_time(philosopher) - philosopher->last_meal > mem->t_death)
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
				return(NULL);
			}
			pthread_mutex_unlock(philosopher->memory->all_full_mutex);
			pthread_mutex_unlock(philosopher->last_meal_mutex);
			return(NULL);
		}
		pthread_mutex_unlock(philosopher->last_meal_mutex);
		pthread_mutex_lock(philosopher->memory->died_mutex);
		if (philosopher->memory->died == 1)
		{
			pthread_mutex_unlock(philosopher->memory->died_mutex);
			return(NULL);
		}
		pthread_mutex_unlock(philosopher->memory->died_mutex);
		philosopher = philosopher->next;
		usleep(1);
	}
}

void *philo_process(void *philosopher)
{
	t_philosopher *philo = (t_philosopher *)philosopher;
	int i = 0;
	pthread_mutex_lock(philo->memory->threads_created_mutex);
	pthread_mutex_unlock(philo->memory->threads_created_mutex);
	if(philo->memory->num_philo == 1)
	{
		pthread_mutex_lock(philo->fork_mutex);
		print_event(philo, FORK);
		my_usleep(philo->memory->t_death, philo);
		pthread_mutex_unlock(philo->fork_mutex);
		print_event(philo, DEAD);
		pthread_mutex_lock(philo->memory->died_mutex);
		philo->memory->died = 1;
		pthread_mutex_unlock(philo->memory->died_mutex);
		return (NULL);
	}
	while (1)
	{
		if(is_odd(philo->num))
		{
			if (eats(philosopher) == 0 || sleeps(philosopher) == 0 || print_event(philosopher, THINKING) == 0)
				return (NULL);
		}
		else
		{
			if (print_event(philosopher, THINKING) == 0)
				return (NULL);
			if (i == 0)
			{
				
				my_usleep(philo->memory->t_eat, philo);
				i++;
			}
			if (eats(philosopher) == 0 || sleeps(philosopher) == 0)
				return (NULL);
		}
	}
	return (NULL);
	}
