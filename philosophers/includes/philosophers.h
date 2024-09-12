/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/12 14:13:36 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILISOPHERS_H
# define PHILISOPHERS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h> 
#include <pthread.h>

typedef struct s_philosopher
{
	pthread_t		p_thread;
	int				num;
	int				is_eating;
	int				is_dead;
	int 			is_full;
	int				times_eaten;
	size_t			t_sleep;
	pthread_mutex_t *fork;
	// pthread_mutex_t *r_fork;
}	t_philisopher;

typedef struct s_memory
{
	t_philisopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	t_params		params;
}	t_memory;

typedef struct s_params
{
	int	num_philo;
	int	t_death;
	int	t_eat;
	// int	t_sleep;
	int	max_meals;
	int died;
	time_t start_time;
}	t_params;

//process.c
void do_something();

#endif