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

static void	is_not_overflow(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]) || (s[i] == '0' && s[i - 1] == '-'))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		is_not_overflow(av[i]);
		is_num(av[i]);
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
static void sort_three(t_everything *e)
{
	int a;
	int b;
	int c;

	a = (*e->stack_a)->num;
	b =(*e->stack_a)->next->num;
	c =(*e->stack_a)->prev->num;
	if(a < b && a > c && b > c)
		rotate(e->stack_a, 1 , 'a', e->commands);
	else if(a > b && a < c && b < c)
		swap(e->stack_a, 'a', e->commands);
	else if(a > b && a > c && b < c)
		rotate(e->stack_a, 0 , 'a', e->commands);
	else if(a > b && a > c && b > c)
	{
		swap(e->stack_a, 'a', e->commands);
		rotate(e->stack_a, 1 , 'a', e->commands);
	}
	else if(a < b && a < c && b > c)
	{
		swap(e->stack_a, 'a', e->commands);
		rotate(e->stack_a, 0 , 'a', e->commands);
	}
}

static void sort_four(t_everything *e)
{
	while((*e->stack_a)->i_srt != 0 )
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 0), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	sort_three(e);
	push(e->stack_b, e->stack_a, 'a', e->commands);
}

static void sort_five(t_everything *e)
{
	while((*e->stack_a)->i_srt != 0 && (*e->stack_a)->i_srt != 1)
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 1), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	while((*e->stack_a)->i_srt != 0 && (*e->stack_a)->i_srt != 1)
		rotate(e->stack_a, find_cheapest(e->stack_a, 0, 1), 'a', e->commands);
	push(e->stack_a, e->stack_b, 'b', e->commands);
	sort_three(e);
	push(e->stack_b, e->stack_a, 'a', e->commands);
	push(e->stack_b, e->stack_a, 'a', e->commands);
	if ((*e->stack_a)->num > (*e->stack_a)->next->num)
		swap(e->stack_a, 'a', e->commands);
}

void	hardcode_solution(t_everything *e)
{
	if (ft_stacksize(e->stack_a) == 2)
	{
		if ((*e->stack_a)->num > (*e->stack_a)->next->num)
			swap(e->stack_a, 'a', e->commands);
	}
	else if (ft_stacksize(e->stack_a) == 3)
		sort_three(e);
	else if (ft_stacksize(e->stack_a) == 4)
		sort_four(e);
	else if (ft_stacksize(e->stack_a) == 5)
		sort_five(e);
	trim_command_list(e->commands);
	print_command_list(e->commands);
	return ;
}

int	main(int ac, char **av)
{
	t_everything	*everything;

	check_input(ac, av);
	everything = NULL;
	everything = set_everything(everything, ac, av);
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
