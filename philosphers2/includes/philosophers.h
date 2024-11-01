/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 10:39:24 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
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
	int				full_philosophers;
	// pthread_mutex_t	*threads_created_mutex;
	
	pthread_mutex_t	*status;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*last_meal_mutex;

	pthread_t		*philosopher_threads;
	pthread_t		overseer_thread;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
}	t_memory;

typedef struct s_philosopher
{
	pthread_mutex_t			*l_fork_mutex;
	pthread_mutex_t			*r_fork_mutex;
	long long				last_meal;
	int						num;
	int						times_eaten;
	t_memory				*memory;
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
int	create_philosophers(t_memory *memory);

//testing.c
// void	print_philosophers(t_memory *memory);
// void	print_memory(t_memory *memory);
int		single_philo_process(t_philosopher *philosopher);
int		is_odd(int i);
void	lock_forks(t_philosopher *phil);
void	unlock_forks(t_philosopher *phil);

//cleanup.c
int	cleanup(t_memory *memory);
int	free_allocs(t_memory *memory);
int	free_memory(t_memory *memory);

//time.c
int		check_sim_end(t_philosopher *philospher);
void	my_usleep(long time, t_philosopher *philosopher);
int		get_current_time(t_philosopher *phil);

//activities.c
int		eats(t_philosopher *phil);
int		sleeps(t_philosopher *phil);

//libft.c
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

//libft1.c
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	ft_bzero(void *ptr, size_t num);

#endif