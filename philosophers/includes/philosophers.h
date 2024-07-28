/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/06 14:25:26 by sopperma         ###   ########.fr       */
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
	int				times_eaten;
	size_t			t_sleep;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
}	t_philisopher;

typedef struct s_params
{
	int	num_philo;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	max_meals;
	int died;
}	t_params;

#endif