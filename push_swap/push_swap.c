/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sopperma <sopperma@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/13 10:04:40 by sopperma		  #+#	#+#			 */
/*   Updated: 2024/05/31 14:24:14 by sopperma		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
// check_sort(stack_a);
// check_swap(stack_a);
// check_push(stack_a, stack_b);
// check_rotate(stack_a);

static t_everything	*set_everything(t_everything *everything, int ac, char **av)
{
	everything = malloc(sizeof(t_everything));
	if (!everything || ac < 2)
		return (free_everything(everything), NULL);
	everything->stack_a = create_stack(ac, av);
	if (!everything->stack_a)
		return (free_everything(everything), NULL);
	everything->stack_b = malloc(sizeof(t_num));
	if (!everything->stack_b)
		return (free_everything(everything), NULL);
	*(everything->stack_b) = NULL;
	everything->commands = malloc (sizeof(t_command));
	if (!everything->commands)
		return (free_everything(everything), NULL);
	*everything->commands = NULL;
	return (everything);
}

//single line input
//don't sort already sorted

int	main(int ac, char **av)
{
	t_everything	*everything;
	
	if (ac == 2)
	{
		ac = countwords(av[1], ' ');
		av = ft_split(av[1], ' ');
		check_input_2(ac, av);
	}
	else
		check_input(ac, av);
	everything = NULL;
	everything = set_everything(everything, ac, av);
	print_list(everything->stack_a, "num");
	if (!everything)
		return (0);
	sort_assign(everything->stack_a);
	if (ac <= 6)
		hardcode_solution(everything);
	else
	{
		everything->params = set_params(everything->stack_a);
		if (everything->params)
		{
			first_stage(everything);
			second_stage(everything);
		}
	}
	return (free_everything(everything), 0);
}
