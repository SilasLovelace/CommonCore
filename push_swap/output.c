/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:06:47 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 11:48:41 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_command(t_command **command_list, char *command)
{
	t_command	*new_command;
	t_command	*element;

	if (!command)
		return ;
	new_command = malloc(sizeof(t_command));
	if (!new_command)
		return ;
	new_command->command = ft_strdup(command);
	if (!new_command->command)
		return (free(new_command));
	new_command->next = NULL;
	if (!command_list || !(*command_list))
		*command_list = new_command;
	else
	{
		element = *command_list;
		while (element ->next)
		{
			element = element -> next;
		}
		element ->next = new_command;
	}
}

void	print_command_list(t_command **command_list)
{
	t_command	*element;

	if (!command_list || !(*command_list))
		return ;
	element = *command_list;
	while (element)
	{
		write(1, element->command, ft_strlen(element->command));
		write(1, "\n", 1);
		element = element -> next;
	}
}

static int	checkdouble(t_command *element, char *des1, char *des2)
{
	if ((ft_strcmp(element->command, des1) == 0 && \
		ft_strcmp(element->next->command, des2) == 0) || \
		(ft_strcmp(element->command, des2) == 0 && \
		ft_strcmp(element->next->command, des1) == 0))
		return (1);
	else
		return (0);
}

static void	freereplace(t_command *element, char *descriptor)
{
	t_command	*to_free;

	element->command = ft_strdup(descriptor);
	to_free = element->next;
	element->next = element->next->next;
	free(to_free->command);
	free(to_free);
}

void	trim_command_list(t_command **command_list)
{
	t_command	*element;

	if (!command_list || !(*command_list))
		return ;
	element = *command_list;
	while (element && element->next)
	{
		if (checkdouble(element, "ra", "rb"))
			freereplace(element, "rr");
		else if (checkdouble(element, "rra", "rrb"))
			freereplace(element, "rrr");
		else
			element = element->next;
	}
}
