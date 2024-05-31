/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:12:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/31 13:27:18 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_num **stack, char *field)
{
	t_num	*list;

	if (!stack || !*stack)
	{
		write(1, "empty\n", 6);
		return ;
	}
	list = *stack;
	while (list)
	{
		if (ft_strncmp(field, "num", ft_strlen(field)) == 0)
			ft_putnbr_fd(list->num, 1);
		if (ft_strncmp(field, "input", ft_strlen(field)) == 0)
			ft_putnbr_fd(list->i_in, 1);
		if (ft_strncmp(field, "sorted", ft_strlen(field)) == 0)
			ft_putnbr_fd(list->i_srt, 1);
		write(1, " ", 1);
		list = list -> next;
		if (list == *stack)
			break ;
	}
	write(1, "\n", 1);
}

static void	assign_ordered_i(t_num **head)
{
	int		c;
	t_num	*current;

	c = 0;
	if (!head || !(*head))
		return ;
	current = *head;
	while (current)
	{
		current ->i_srt = c++;
		current = current ->next;
		if (current == *head)
			break ;
	}
}

void	sort_assign(t_num **stack_a)
{
	bubble_sort(stack_a, "num");
	assign_ordered_i(stack_a);
	bubble_sort(stack_a, "input");
}
