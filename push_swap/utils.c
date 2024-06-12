/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:12:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/12 11:32:45 by sopperma         ###   ########.fr       */
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

void	sort_assign(t_everything *e)
{
	bubble_sort(e->stack_a, "num");
	assign_ordered_i(e->stack_a);
	bubble_sort(e->stack_a, "input");
}

/* static int check_doubles(t_num **head)
{
	int		c;
	t_num	*current;
	t_num	*compare;

	c = 0;
	if (!head || !(*head))
		return (0);
	current = *head;
	compare = current->next;
	while (current)
	{
		compare = current->next;
		while(compare != *head)
		{
			if (current->num == compare->num)
				return (0);
			compare = compare->next;
		}
		current = current->next;
		if (current == *head)
			break ;
	}
	return (1);
}

int	sort_assign(t_everything *e)
{
	if (!check_doubles(e->stack_a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	bubble_sort(e->stack_a, "num");
	assign_ordered_i(e->stack_a);
	bubble_sort(e->stack_a, "input");
	return (1);
}
 */