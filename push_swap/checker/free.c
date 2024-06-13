/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:09:16 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/12 19:17:24 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_num_list(t_num *num_list)
{
	t_num	*temp;
	t_num	*start;

	start = num_list;
	while (num_list)
	{
		temp = num_list->next;
		free(num_list);
		if (temp == start)
			break ;
		num_list = temp;
	}
}

void	free_command_list(t_command *command_list)
{
	t_command	*temp;

	while (command_list)
	{
		temp = command_list->next;
		free(command_list);
		command_list = temp;
	}
}

void	free_av(char **strings, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(strings[i++]);
	}
}

static void	free_everything_helper(t_everything *everything)
{
	if (everything)
	{
		if (everything->params)
			free(everything->params);
		if (everything->joined)
			free(everything->joined);
		if (everything->ac != everything->true_ac || \
			everything->one_param_assigned)
		{
			free_av(everything->av, everything->ac);
			free(everything->av);
		}
		if (everything->single)
			free(everything->single);
	}
}

void	free_everything(t_everything *everything)
{
	if (everything)
	{
		if (everything->stack_a)
		{
			free_num_list(*(everything->stack_a));
			free(everything->stack_a);
		}
		if (everything->stack_b)
		{
			free_num_list(*(everything->stack_b));
			free(everything->stack_b);
		}
		if (everything->commands)
		{
			free_command_list(*(everything->commands));
			free(everything->commands);
		}
		free_everything_helper(everything);
		free(everything);
		everything = NULL;
	}
}
