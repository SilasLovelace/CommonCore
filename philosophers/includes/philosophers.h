/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/09/26 14:17:07 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILISOPHERS_H
# define PHILISOPHERS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h> 
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_philosopher t_philosopher;
typedef struct s_memory
{
	int	num_philo;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	max_meals;
	int died;
	int all_ate;
	int full_philosophers;
	long long start_time;
	pthread_t		overseer_thread;
	t_philosopher	*philosophers;
	pthread_mutex_t	*full;
	pthread_mutex_t	*print;
	pthread_mutex_t	*get_time;
	pthread_mutex_t	*death;
}	t_memory;

typedef struct s_philosopher
{
	pthread_t		p_thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*is_eating_mutex;
	int				num;
	int				is_dead;
	int 			is_eating;
	int				times_eaten;
	long long			last_eat_time;
	t_memory		*memory;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philosopher;


//process.c
void *do_something(void *philosopher);
int get_current_time(t_philosopher *phil);

//setup.c
void create_philosophers(t_memory *memory);

//testing.c
void print_philosophers(t_memory *memory);
void print_memory(t_memory *memory);

#endif