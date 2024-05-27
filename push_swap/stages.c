/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:26:05 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/27 17:38:01 by sopperma         ###   ########.fr       */
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
	params->upper_limit = params->middle + params->chunk_size;
	params->lower_limit = params->middle - params->chunk_size;
	return (params);
}

void	first_stage(t_num **stack_a, t_num **stack_b, \
	t_params *params, t_command **command_list)
{
	while (find_cheapest(stack_a, params->lower_limit, params->upper_limit) \
		> -1)
	{
		while (find_cheapest(stack_a, params->lower_limit, params->upper_limit) \
			> -1)
		{
			if ((*stack_a)->i_sorted >= params->lower_limit
				&& (*stack_a)->i_sorted <= params->upper_limit)
				break ;
			rotate(stack_a, find_cheapest(stack_a, params->lower_limit, \
			params->upper_limit), 'a', command_list);
		}
		push(stack_a, stack_b, 'b', command_list);
		if ((*stack_b)->i_sorted < params->middle)
			rotate(stack_b, 0, 'b', command_list);
		if (find_cheapest(stack_a, params->lower_limit, params->middle) < 0)
			params->lower_limit -= params->chunk_size;
		if (find_cheapest(stack_a, params->middle, params->upper_limit) < 0)
			params->upper_limit += params->chunk_size;
	}
}

static void	rotate_biggest_to_top(t_num **stack, t_command **command_list)
{
	int	biggest;

	biggest = ft_biggest(stack);
	while (!((*stack)->i_sorted == biggest))
		rotate(stack, find_cheapest(stack, biggest, biggest), \
		'b', command_list);
}

void	second_stage(t_num **stack_a, t_num **stack_b, t_command **command_list)
{
	int	bottom;

	bottom = 0;
	rotate_biggest_to_top(stack_b, command_list);
	while (ft_biggest(stack_b) >= 0)
	{
		if (!(ft_stacksize(stack_a)) \
			|| (*stack_b)->i_sorted == (*stack_a)->i_sorted -1)
		{
			push(stack_b, stack_a, 'a', command_list);
			if (bottom)
				bottom = rotate_combine(stack_a, 'a', command_list, bottom);
		}
		else if ((*stack_b)->i_sorted > (*stack_a)->prev->i_sorted || !bottom)
		{
			push(stack_b, stack_a, 'a', command_list);
			rotate(stack_a, 0, 'a', command_list);
			bottom++;
		}
		else
			rotate(stack_b, find_cheapest(stack_b, (*stack_a) \
			->prev->i_sorted + 1, (*stack_a)->i_sorted - 1), 'b', command_list);
	}
	trim_command_list(command_list);
	print_command_list(command_list);
}
