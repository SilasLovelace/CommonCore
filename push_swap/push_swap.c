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
	everything->stack_a = create_stack(ac, av);
	if (!everything->stack_a || check_sorted(everything->stack_a))
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

static t_everything	*create_everything(t_everything *everything)
{
	everything = malloc(sizeof(t_everything));
	if (!everything)
		return (free_everything(everything), NULL);
	ft_bzero(everything, sizeof(t_everything));
	return (everything);
}

static int	check_single(t_everything *everything, char **av)
{
	if (countwords(av[1], ' ') == 1)
	{
		everything->single = ft_strtrim(av[1], " ");
		if (!everything->single)
			return (free_everything(everything), 0);
		everything->joined = ft_strjoin("test ", everything->single);
		if (!everything->joined)
			return (free_everything(everything), 0);
		everything->one_param_assigned = 1;
	}
	else
	{
		everything->joined = ft_strjoin("test ", av[1]);
		if (!everything->joined)
			return (free_everything(everything), 0);
	}
	everything->av = ft_split(everything->joined, ' ');
	if (!everything->av)
		return (free_everything(everything), 0);
	everything->ac = countwords(everything->joined, ' ');
	return (1);
}

static t_everything	*prepare_everything(int ac, char **av)
{
	t_everything	*everything;

	everything = NULL;
	everything = create_everything(everything);
	if (!everything || ac == 1 || !av[1][0])
		return (free_everything(everything), NULL);
	if (ac == 2)
	{
		if (!check_single(everything, av))
			return (NULL);
	}
	else
	{
		everything->av = av;
		everything->ac = ac;
	}
	everything->true_ac = ac;
	return (everything);
}

//potentially handle -0 0 ???
int	main(int ac, char **av)
{
	t_everything	*everything;

	everything = prepare_everything(ac, av);
	if (!everything)
		return (0);
	check_input(everything);
	everything = set_everything(everything, everything->ac, everything->av);
	if (!everything)
		return (0);
	sort_assign(everything);
	if (everything->ac <= 6)
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
