/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/16 13:16:32 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h> 
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philosopher	t_philosopher;
typedef struct s_memory
{
	int				num_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				max_meals;
	long long		start_time;
	int				dead_philosopher;
	int				died;
	pthread_mutex_t	*died_mutex;
	int				all_full;
	pthread_mutex_t	*all_full_mutex;
	int				full_philosophers;
	pthread_mutex_t	*full_mutex;
	pthread_mutex_t	*threads_created_mutex;
	pthread_t		overseer_thread;
	t_philosopher	*philosophers;
	pthread_mutex_t	*print_mutex;
}	t_memory;

typedef struct s_philosopher
{
	pthread_t				fork;
	pthread_mutex_t			*fork_mutex;
	long long				last_meal;
	pthread_mutex_t			*last_meal_mutex;
	int						num;
	int						times_eaten;
	t_memory				*memory;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philosopher;

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define FULL 4
# define DEAD 5
# define FORK 6
# define FORK 6

# define ARGUMENT_OVERFLOW 1
# define PHILO_NUM_ERROR 2
# define PHILO_EAT_ERROR 3
# define PHILO_TIME_ERROR 4

//process.c
void	*philo_process(void *philosopher);
int		get_current_time(t_philosopher *phil);
int		print_event(t_philosopher *phil, char event);
void	*overseer(void *memory);

//setup.c
void	create_philosophers(t_memory *memory);

//testing.c
void	print_philosophers(t_memory *memory);
void	print_memory(t_memory *memory);

//cleanup.c
void	cleanup(t_memory *memory);

#endif