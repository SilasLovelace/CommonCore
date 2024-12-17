/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_allocations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:21:38 by sopperma          #+#    #+#             */
/*   Updated: 2024/11/01 11:24:52 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_error(int error)
{
	if (error == ARGUMENT_OVERFLOW)
		ft_putstr_fd("Error: Argument overflows!\n", 2);
	if (error == PHILO_NUM_ERROR)
		ft_putstr_fd \
			("Error: There must be at least 1 and max 200 philosophers\n", 2);
	if (error == PHILO_EAT_ERROR)
		ft_putstr_fd("Error: Number of meals must be at least 1\n", 2);
	if (error == PHILO_TIME_ERROR)
		ft_putstr_fd("Error: Time must be at least 60ms\n", 2);
	return (0);
}

int	check_inputs(int ac, char **av)
{
	int		i;
	char	*num;

	i = 1;
	while (i < ac)
	{
		num = ft_itoa(ft_atoi(av[i]));
		if (ft_strncmp(num, \
			av[i], ft_strlen(av[i])) != 0)
		{
			free(num);
			return (free_error(ARGUMENT_OVERFLOW));
		}
		free(num);
		i++;
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (free_error(PHILO_NUM_ERROR));
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (free_error(PHILO_EAT_ERROR));
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (free_error(PHILO_TIME_ERROR));
	return (1);
}

int	allocate_arrays(t_memory *memory)
{
	memory->philosophers = malloc(sizeof(t_philosopher) * (memory->num_philo));
	if (memory->philosophers == NULL)
		return (free_allocs(memory));
	memory->philosopher_threads = \
		malloc(sizeof(pthread_t) * (memory->num_philo));
	if (memory->philosopher_threads == NULL)
		return (free_allocs(memory));
	memory->forks = malloc(sizeof(pthread_mutex_t) * (memory->num_philo));
	if (memory->forks == NULL)
		return (free_allocs(memory));
	return (1);
}
