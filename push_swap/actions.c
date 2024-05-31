/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:16:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/31 15:41:48 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	writecommand(char *command, char ab, t_command **commands)
{
	if (!ft_strncmp(command, "r", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(commands, "ra");
		else
			add_command(commands, "rb");
	}
	else if (!ft_strncmp(command, "rr", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(commands, "rra");
		else
			add_command(commands, "rrb");
	}
	else if (!ft_strncmp(command, "p", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(commands, "pa");
		else
			add_command(commands, "pb");
	}
	else if (!ft_strncmp(command, "s", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(commands, "sa");
		else
			add_command(commands, "sb");
	}
}

static void	insert_node(t_num *push_node, t_num **b)
{
	t_num	*tail;

	if (b && *b)
	{
		tail = (*b)->prev;
		push_node->next = *b;
		push_node->prev = tail;
		tail->next = push_node;
		(*b)->prev = push_node;
		*b = push_node;
	}
	else
	{
		push_node->next = push_node;
		push_node->prev = push_node;
		*b = push_node;
	}
}

void	push(t_num **a, t_num **b, char ab, t_command **commands)
{
	t_num	*push_node;
	t_num	*tail;

	if (!a || !*a)
		return ;
	push_node = *a;
	if ((*a)->next == *a)
		*a = NULL;
	else
	{
		tail = (*a)->prev;
		*a = (*a)->next;
		(*a)->prev = tail;
		tail->next = *a;
	}
	insert_node(push_node, b);
	writecommand("p", ab, commands);
}
void	swap(t_num **stack, char ab, t_command **commands)
{
	t_num	*a = *stack;
	t_num	*b = (*stack)->next;
	t_num	*temp;

	if (!stack || !*stack)
		return ;
	temp = a;
	a->num = b->num;
	a->i_in = b->i_in;
	a->i_srt = b->i_srt;
	b->num = temp->num;
	b->i_in = temp->i_in;
	b->i_srt = temp->i_srt;
    writecommand ("s", ab, commands);
}

void	rotate(t_num **stack, int reverse, char ab, t_command **commands)
{
	if (reverse < 0)
		return ;
	if (reverse == RR)
	{
		*stack = (*stack)->prev;
		writecommand("rr", ab, commands);
	}
	else if (reverse == R)
	{
		*stack = (*stack)->next;
		writecommand("r", ab, commands);
	}
}
