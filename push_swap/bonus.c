/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:18 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/12 19:27:59 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static t_everything	*set_everything(t_everything *everything, int ac, char **av)
{
	everything->stack_a = create_stack(ac, av);
	if (!everything->stack_a || check_sorted(everything->stack_a))
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
int	is_valid(char *op)
{
	if (!ft_strncmp(op, "sa", 3) || !ft_strncmp(op, "sb", 3)
		|| !ft_strncmp(op, "ss", 3) || !ft_strncmp(op, "pa", 3)
		|| !ft_strncmp(op, "pb", 3) || !ft_strncmp(op, "ra", 3)
		|| !ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rr", 3)
		|| !ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rrb", 4)
		|| !ft_strncmp(op, "rrr", 4))
		return (1);
	return (0);
}

void    execute(char *op, t_everything *e)
{
    if (!ft_strncmp(op, "sa", 3) || ft_strncmp(op, "ss", 3) && e->stack_a)
        swap(e->stack_a, 'a', e->commands);
    if (!ft_strncmp(op, "sb", 3) || ft_strncmp(op, "ss", 3) && e->stack_b)
        swap(e->stack_a, 'b', e->commands);
    if (!ft_strncmp(op, "pa", 3))
        push(e->stack_b, e->stack_a, 'a', e->commands);
	if (!ft_strncmp(op, "pb", 3))
        push(e->stack_a, e->stack_b, 'b', e->commands);
    if (!ft_strncmp(op, "ra", 3) || !ft_strncmp(op, "rr", 3) && e->stack_a)
        rotate(e->stack_a, R, 'a', e->commands);
	if (!ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rr", 3) && e->single)
        rotate(e->stack_a, R, 'b', e->commands);
    if (!ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rrr", 4) && e->stack_a)
        rotate(e->stack_a, RR, 'a', e->commands);
    if (!ft_strncmp(op, "rrb", 4) || !ft_strncmp(op, "rrr", 4) && e->stack_b)
        rotate(e->stack_a, RR, 'a', e->commands);
}

static int  perform_operation(t_everything *e)
{
	char		*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!is_valid(operation))
		{
			write(1, "Error", 6);
			free_everything(e);
			free(operation);
			return (0);
		}
		execute(operation, e);
		free(operation);
		operation = get_next_line(0);
	}
	if (check_sorted(e->stack_a) && !e->stack_b)
		write(1, "OK\n", 3);
	else
		(write(1, "KO\n", 3));
	return (1);
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