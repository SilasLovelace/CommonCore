/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_input_solutions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:51:37 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/10 15:59:38 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_everything *e)
{
	int	a;
	int	b;
	int	c;

	a = (*e->stack_a)->num;
	b = (*e->stack_a)->next->num;
	c = (*e->stack_a)->prev->num;
	if (a < b && a > c && b > c)
		rotate(e->stack_a, 1, 'a', e->commands);
	else if (a > b && a < c && b < c)
		swap(e->stack_a, 'a', e->commands);
	else if (a > b && a > c && b < c)
		rotate(e->stack_a, 0, 'a', e->commands);
	else if (a > b && a > c && b > c)
	{
		swap(e->stack_a, 'a', e->commands);
		rotate(e->stack_a, 1, 'a', e->commands);
	}
	else if (a < b && a < c && b > c)
	{
		swap(e->stack_a, 'a', e->commands);
		rotate(e->stack_a, 0, 'a', e->commands);
	}
}

static void	sort_four(t_everything *e)
{
	while ((*e->stack_a)->i_srt != 0)
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 0), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	sort_three(e);
	push(e->stack_b, e->stack_a, 'a', e->commands);
}

static void	sort_five(t_everything *e)
{
	while ((*e->stack_a)->i_srt != 0 && (*e->stack_a)->i_srt != 1)
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 1), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	while ((*e->stack_a)->i_srt != 0 && (*e->stack_a)->i_srt != 1)
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 1), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	sort_three(e);
	push(e->stack_b, e->stack_a, 'a', e->commands);
	push(e->stack_b, e->stack_a, 'a', e->commands);
	if ((*e->stack_a)->num > (*e->stack_a)->next->num)
		swap(e->stack_a, 'a', e->commands);
}

void	hardcode_solution(t_everything *e)
{
	if (ft_stacksize(e->stack_a) == 2)
	{
		if ((*e->stack_a)->num > (*e->stack_a)->next->num)
			swap(e->stack_a, 'a', e->commands);
	}
	else if (ft_stacksize(e->stack_a) == 3)
		sort_three(e);
	else if (ft_stacksize(e->stack_a) == 4)
		sort_four(e);
	else if (ft_stacksize(e->stack_a) == 5)
		sort_five(e);
	trim_command_list(e->commands);
	print_command_list(e->commands);
	return ;
}
