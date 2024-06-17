/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:36:51 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/17 14:09:49 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_num	**create_link_stack(t_num *first, t_num *last)
{
	t_num	**stack;

	stack = malloc(sizeof(t_num));
	if (!stack)
		return (free_num_list(first), NULL);
	*stack = first;
	last -> next = first;
	first -> prev = last;
	return (stack);
}

t_num	**create_stack(int ac, char **av)
{
	int		c;
	t_num	*first;
	t_num	*last;
	int		num;

	c = 1;
	ft_atoi(av[c], &num);
	first = ft_lstnew(num, c - 1);
	if (!first)
		return (NULL);
	c++;
	last = first;
	while (c < ac)
	{
		ft_atoi(av[c], &num);
		last ->next = ft_lstnew(num, c - 1);
		if (!last -> next)
			return (free_num_list(first), NULL);
		last->next->prev = last;
		last = last -> next;
		c++;
	}
	return (create_link_stack(first, last));
}
