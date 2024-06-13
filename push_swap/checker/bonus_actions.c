/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:09:49 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/13 16:31:09 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static int	is_valid(char *op)
{
	if (!ft_strncmp(op, "sa\n", 3) || !ft_strncmp(op, "sb\n", 3)
		|| !ft_strncmp(op, "ss\n", 3) || !ft_strncmp(op, "pa\n", 3)
		|| !ft_strncmp(op, "pb\n", 3) || !ft_strncmp(op, "ra\n", 3)
		|| !ft_strncmp(op, "rb\n", 3) || !ft_strncmp(op, "rr\n", 3)
		|| !ft_strncmp(op, "rra\n", 4) || !ft_strncmp(op, "rrb\n", 4)
		|| !ft_strncmp(op, "rrr\n", 4))
		return (1);
	return (0);
}

static void	execute(char *op, t_everything *e)
{
	if ((!ft_strncmp(op, "sa\n", 3) || !ft_strncmp(op, "ss\n", 3)) \
		&& e->stack_a)
		swap(e->stack_a, 'a', e->commands);
	if ((!ft_strncmp(op, "sb\n", 3) || !ft_strncmp(op, "ss\n", 3)) \
		&& e->stack_b)
		swap(e->stack_b, 'b', e->commands);
	if (!ft_strncmp(op, "pa\n", 3))
		push(e->stack_b, e->stack_a, 'a', e->commands);
	if (!ft_strncmp(op, "pb\n", 3))
		push(e->stack_a, e->stack_b, 'b', e->commands);
	if ((!ft_strncmp(op, "ra\n", 3) || !ft_strncmp(op, "rr\n", 3)) \
		&& e->stack_a)
		rotate(e->stack_a, R, 'a', e->commands);
	if ((!ft_strncmp(op, "rb\n", 3) || !ft_strncmp(op, "rr\n", 3)) \
		&& e->stack_b)
		rotate(e->stack_a, R, 'b', e->commands);
	if ((!ft_strncmp(op, "rra\n", 4) || !ft_strncmp(op, "rrr\n", 4)) \
		&& e->stack_a)
		rotate(e->stack_a, RR, 'a', e->commands);
	if ((!ft_strncmp(op, "rrb\n", 4) || !ft_strncmp(op, "rrr\n", 4)) \
		&& e->stack_b)
		rotate(e->stack_a, RR, 'b', e->commands);
}

int	perform_operation(t_everything *e)
{
	char		*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!is_valid(operation))
		{
			write(1, "Error\n", 6);
			free_everything(e);
			free(operation);
			exit(EXIT_FAILURE);
		}
		execute(operation, e);
		free(operation);
		operation = get_next_line(0);
	}
	if (check_sorted(e->stack_a) && !*(e->stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
