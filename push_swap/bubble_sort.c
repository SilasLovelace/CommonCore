/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:52:26 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/12 11:44:51 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_swap(t_num *a, t_num *b)
{
	int	temp;

	temp = a->num;
	a->num = b->num;
	b->num = temp;
	temp = a->i_in;
	a->i_in = b->i_in;
	b->i_in = temp;
	temp = a->i_srt;
	a->i_srt = b->i_srt;
	b->i_srt = temp;
}

static int	check_cond(t_num *ptr, char *field)
{
	if (!ft_strcmp(field, "num"))
		return (ptr->num > ptr->next->num);
	else if (!ft_strcmp(field, "input"))
		return (ptr->i_in > ptr->next->i_in);
	else
		return (-1);
}

int	check_sorted(t_num **head)
{
	t_num	*ptr;

	ptr = *head;
	while (ptr->next)
	{
		if (ptr->next == *head)
			break ;
		if (ptr->num > ptr->next->num)
			return (0);
		if (ptr->num == ptr->next->num)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		ptr = ptr->next;
	}
	return (1);
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
