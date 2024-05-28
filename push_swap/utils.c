/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:12:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 11:14:26 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeif_list(t_num **list)
{
	t_num	*current;
	t_num	*next;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		next = current -> next;
		free(current);
		current = next;
		if (current == *list)
		{
			free(list);
			break ;
		}
	}
}

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
			ft_putnbr_fd(list->i_input, 1);
		if (ft_strncmp(field, "sorted", ft_strlen(field)) == 0)
			ft_putnbr_fd(list->i_sorted, 1);
		write(1, " ", 1);
		list = list -> next;
		if (list == *stack)
			break ;
	}
	write(1, "\n", 1);
}

void	assign_ordered_i(t_num **head)
{
	int		c;
	t_num	*current;

	c = 0;
	if (!head || !(*head))
		return ;
	current = *head;
	while (current)
	{
		current ->i_sorted = c++;
		current = current ->next;
		if (current == *head)
			break ;
	}
}
