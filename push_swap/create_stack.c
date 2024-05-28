/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:36:51 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 12:39:36 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_num	**create_link_stack(t_num *first, t_num *last)
{
	t_num	**stack;

	stack = malloc(sizeof(t_num));
	if (!stack)
		return (freeif_list(&first), NULL);
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

	c = 1;
	first = ft_lstnew(ft_atoi(av[c]), c - 1);
	if (!first)
		return (NULL);
	c++;
	last = first;
	while (c < ac)
	{
		last ->next = ft_lstnew(ft_atoi(av[c]), c - 1);
		if (!last -> next)
			return (freeif_list (&first), NULL);
		last->next->prev = last;
		last = last -> next;
		c++;
	}
	return (create_link_stack(first, last));
}
