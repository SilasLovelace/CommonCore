/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:50:32 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/10 16:58:38 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_not_overflow(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]) || (s[i] == '0' && s[i - 1] == '-'))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

#include <stdio.h>
void	check_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac == 2)
	{
		ac = countwords(av[1], ' ');
		av = ft_split(av[1], ' ');
		i--;
	}
	while (i < ac)
	{
		// printf("%s\n", av[i++]);
		is_not_overflow(av[i]);
		is_num(av[i]);
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
void	check_input_2(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// printf("%d\n", ac);
	while (i < ac)
	{
		// printf("%s ", av[i++]);
		is_not_overflow(av[i]);
		is_num(av[i]);
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
