/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:26:05 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/31 13:19:25 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_params	*set_params(t_num **stack_a)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->middle = ft_stacksize(stack_a) / 2;
	if (ft_stacksize(stack_a) <= 10)
		params->chunks = 5;
	else if (ft_stacksize(stack_a) <= 150)
		params->chunks = 8;
	else
		params->chunks = 18;
	params->chunk_size = ft_stacksize(stack_a) / params->chunks;
	params->upper = params->middle + params->chunk_size;
	params->lower = params->middle - params->chunk_size;
	return (params);
}

void	first_stage(t_everything *e)
{
	while (find_cheapest(e->stack_a, e->params->lower, \
	e->params->upper) > -1)
	{
		while (find_cheapest(e->stack_a, e->params->lower, \
		e->params->upper) > -1)
		{
			if ((*e->stack_a)->i_srt >= e->params->lower
				&& (*e->stack_a)->i_srt <= e->params->upper)
				break ;
			rotate(e->stack_a, find_cheapest(e->stack_a, \
			e->params->lower, e->params->upper), 'a', e->commands);
		}
		push(e->stack_a, e->stack_b, 'b', e->commands);
		if ((*e->stack_b)->i_srt < e->params->middle)
			rotate(e->stack_b, 0, 'b', e->commands);
		if (find_cheapest(e->stack_a, e->params->lower, e->params->middle) < 0)
			e->params->lower -= e->params->chunk_size;
		if (find_cheapest(e->stack_a, e->params->middle, e->params->upper) < 0)
			e->params->upper += e->params->chunk_size;
	}
}

static void	rotate_biggest_to_top(t_num **stack, t_command **command_list)
{
	int	biggest;

	biggest = ft_biggest(stack);
	while (!((*stack)->i_srt == biggest))
		rotate(stack, find_cheapest(stack, biggest, biggest), \
		'b', command_list);
}

void	second_stage(t_everything *e)
{
	int	bottom;

	bottom = 0;
	rotate_biggest_to_top(e->stack_b, e->commands);
	while (ft_biggest(e->stack_b) >= 0)
	{
		if (!(ft_stacksize(e->stack_a)) \
			|| (*e->stack_b)->i_srt == (*e->stack_a)->i_srt -1)
		{
			push(e->stack_b, e->stack_a, 'a', e->commands);
			if (bottom)
				bottom = rotate_combine(e->stack_a, 'a', e->commands, bottom);
		}
		else if ((*e->stack_b)->i_srt > (*e->stack_a)->prev->i_srt || !bottom)
		{
			push(e->stack_b, e->stack_a, 'a', e->commands);
			rotate(e->stack_a, 0, 'a', e->commands);
			bottom++;
		}
		else
			rotate(e->stack_b, find_cheapest(e->stack_b, (*e->stack_a) \
			->prev->i_srt + 1, (*e->stack_a)->i_srt - 1), 'b', e->commands);
	}
	trim_command_list(e->commands);
	print_command_list(e->commands);
}
