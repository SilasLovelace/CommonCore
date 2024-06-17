/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:50:32 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/17 14:33:31 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_not_overflow(t_everything *everything, char *s)
{
	long	num;
	int		number;

	num = ft_atoi(s, &number);
	if (!num)
	{
		free_everything(everything);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	is_num(t_everything *everything, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]))
		{
			free_everything(everything);
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_input(t_everything *everything)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < everything->ac)
	{
		is_not_overflow(everything, everything->av[i]);
		is_num(everything, everything->av[i]);
		j = i + 1;
		while (j < everything->ac)
		{
			if (ft_strcmp(everything->av[i], everything->av[j]) == 0)
			{
				free_everything(everything);
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
