/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:04:40 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:06 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check_sort(stack_a);
// check_swap(stack_a);
// check_push(stack_a, stack_b);
// check_rotate(stack_a);
int	main(int ac, char **av)
{
	t_num		**stack_a;
	t_num		**stack_b;
	t_command	**command_list;
	t_params	*params;

	if (ac < 2)
		return (0);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		return (freeif_list (stack_a), 0);
	stack_b = malloc(sizeof(t_num));
	if (!stack_b)
		return (freeif_list (stack_a), 0);
	*stack_b = NULL;
	command_list = malloc (sizeof(t_command));
	if (!command_list)
		return (freeif_list (stack_a), freeif_list (stack_b), 0);
	sort_assign(stack_a);
	params = set_params(stack_a);
	first_stage(stack_a, stack_b, params, command_list);
	second_stage(stack_a, stack_b, command_list);
	return (freeif_list (stack_a), freeif_list(stack_b), 0);
}
