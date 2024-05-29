/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:16:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/29 09:58:00 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	writecommand(char *command, char ab, t_command **command_list)
{
	if (!ft_strncmp(command, "r", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(command_list, "ra");
		else
			add_command(command_list, "rb");
	}
	else if (!ft_strncmp(command, "rr", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(command_list, "rra");
		else
			add_command(command_list, "rrb");
	}
	else if (!ft_strncmp(command, "p", ft_strlen(command)))
	{
		if (ab == 'a')
			add_command(command_list, "pa");
		else
			add_command(command_list, "pb");
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

void	push(t_num **a, t_num **b, char ab, t_command **command_list)
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
	writecommand("p", ab, command_list);
}
/*
void	swap(t_num **a, char ab, t_command **command_list)
{
	t_num	*first_node;
	t_num	*second_node;

	if (!a || !(*a))
		return ;
	first_node = *a;
	if (first_node -> next != first_node)
	{
	second_node = first_node->next;
        // Case where there are only two nodes
        if (second_node->next == first_node)
        {
            first_node->next = second_node;
            first_node->prev = second_node;
            second_node->next = first_node;
            second_node->prev = first_node;
        }
        else
        {
            first_node->next = second_node->next;
            first_node->next->prev = first_node;
            second_node->next = first_node;
            second_node->prev = first_node->prev;
            first_node->prev->next = second_node; 
            // Update the prev of the head to point to the new head
            first_node->prev = second_node;
        }
        *a = second_node;
    }
    writecommand ("s", ab, command_list);
}*/

void	rotate(t_num **stack, int reverse, char ab, t_command **command_list)
{
	if (reverse < 0)
		return ;
	if (reverse == RR)
	{
		*stack = (*stack)->prev;
		writecommand("rr", ab, command_list);
	}
	else if (reverse == R)
	{
		*stack = (*stack)->next;
		writecommand("r", ab, command_list);
	}
}
