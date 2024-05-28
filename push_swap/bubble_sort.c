/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:52:26 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 13:53:49 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_swap(t_num *a, t_num *b)
{
	int	temp;

	temp = a->num;
	a->num = b->num;
	b->num = temp;
	temp = a->i_input;
	a->i_input = b->i_input;
	b->i_input = temp;
	temp = a->i_sorted;
	a->i_sorted = b->i_sorted;
	b->i_sorted = temp;
}

static int	check_cond(t_num *ptr, char *field)
{
	if (!ft_strcmp(field, "num"))
		return (ptr->num > ptr->next->num);
	else if (!ft_strcmp(field, "input"))
		return (ptr->i_input > ptr->next->i_input);
	else
		return (-1);
}

void	bubble_sort(t_num **head, char *field)
{
	int		swapped;
	t_num	*ptr;

	if (head == NULL || *head == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = *head;
		while (ptr->next != *head)
		{
			if (check_cond(ptr, field) < 0)
				return ;
			if (check_cond(ptr, field))
			{
				bubble_swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
	}
}
