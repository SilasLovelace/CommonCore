/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/13 16:29:13 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_everything	*set_everything(t_everything *everything, int ac, char **av)
{
	everything->stack_a = create_stack(ac, av);
	if (!everything->stack_a)
		return (free_everything(everything), NULL);
	everything->stack_b = malloc(sizeof(t_num));
	if (!everything->stack_b)
		return (free_everything(everything), NULL);
	*(everything->stack_b) = NULL;
	everything->commands = malloc (sizeof(t_command));
	if (!everything->commands)
		return (free_everything(everything), NULL);
	*everything->commands = NULL;
	return (everything);
}

static t_everything	*create_everything(t_everything *everything)
{
	everything = malloc(sizeof(t_everything));
	if (!everything)
		return (free_everything(everything), NULL);
	ft_bzero(everything, sizeof(t_everything));
	return (everything);
}

static int	check_single(t_everything *everything, char **av)
{
	if (countwords(av[1], ' ') == 1)
	{
		everything->single = ft_strtrim(av[1], " ");
		if (!everything->single)
			return (free_everything(everything), 0);
		everything->joined = ft_strjoin("test ", everything->single);
		if (!everything->joined)
			return (free_everything(everything), 0);
		everything->one_param_assigned = 1;
	}
	else
	{
		everything->joined = ft_strjoin("test ", av[1]);
		if (!everything->joined)
			return (free_everything(everything), 0);
	}
	everything->av = ft_split(everything->joined, ' ');
	if (!everything->av)
		return (free_everything(everything), 0);
	everything->ac = countwords(everything->joined, ' ');
	return (1);
}

static t_everything	*prepare_everything(int ac, char **av)
{
	t_everything	*everything;

	everything = NULL;
	everything = create_everything(everything);
	if (!everything || ac == 1 || !av[1][0])
		return (free_everything(everything), NULL);
	if (ac == 2)
	{
		if (!check_single(everything, av))
			return (NULL);
	}
	else
	{
		everything->av = av;
		everything->ac = ac;
	}
	everything->true_ac = ac;
	return (everything);
}

int	main(int ac, char **av)
{
	t_everything	*everything;

	everything = prepare_everything(ac, av);
	if (!everything)
		return (0);
	check_input(everything);
	everything = set_everything(everything, everything->ac, everything->av);
	if (!everything)
		return (0);
	if (!sort_assign(everything))
		return (free_everything(everything), 0);
	perform_operation(everything);
	return (free_everything(everything), 0);
}
