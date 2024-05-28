/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:20:35 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 10:56:30 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_price(t_num **stack, int direction, \
	int range_min, int range_max)
{
	int		rotate_price;
	t_num	*current;

	rotate_price = 0;
	current = *stack;
	while (current)
	{
		if (current->i_sorted >= range_min && current->i_sorted <= range_max)
			break ;
		rotate_price++;
		if (!direction)
			current = current->next;
		else if (direction)
			current = current->prev;
		if (current == *stack)
			return (-1);
	}
	return (rotate_price);
}

int	find_cheapest(t_num **stack, int range_min, int range_max)
{
	int	rotate_price;
	int	rev_rotate_price;

	if (!stack || !(*stack))
		return (-1);
	rotate_price = (find_price(stack, 0, range_min, range_max));
	rev_rotate_price = (find_price(stack, 1, range_min, range_max));
	if (rotate_price < 0 || rev_rotate_price < 0)
		return (-1);
	if (rotate_price < rev_rotate_price)
		return (0);
	return (1);
}
