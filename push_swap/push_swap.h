/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:18:54 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/31 14:27:00 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_num
{
	int				i_in;
	int				i_srt;
	int				num;
	struct s_num	*next;
	struct s_num	*prev;
}	t_num;

typedef struct s_params
{
	int	stack_size;
	int	chunks;
	int	middle;
	int	chunk_size;
	int	upper;
	int	lower;
}	t_params;

typedef struct s_command
{
	char				*command;
	struct s_command	*next;
}	t_command;

typedef enum s_rotation_directions
{
	R,
	RR,
}	t_directions;

typedef struct s_everything
{
	t_num		**stack_a;
	t_num		**stack_b;
	t_command	**commands;
	t_params	*params;
}	t_everything;

void		trim_command_list(t_command **command_list);
void		add_command(t_command **command_list, char *command);
void		print_command_list(t_command **command_list);
int			num_instructions(t_command **command_list);
int			rotate_combine(t_num **stack, char ab, \
	t_command **command_list, int bottom);
void		check_swap(t_num **stack_a);
void		check_push(t_num **stack_a, t_num **stack_b);
void		check_rotate(t_num **stack_a);
void		check_sort(t_num **stack_a);
void		sort_assign(t_num **stack_a);
t_params	*set_params(t_num **stack_a);
void		first_stage(t_everything *everything);
void		second_stage(t_everything *everything);

int			find_cheapest(t_num **stack, int range_min, int range_max);
int			ft_biggest(t_num **stack);

t_num		*ft_lstnew(int num, int i);
t_num		*ft_lstlast(t_num *lst);
void		print_list(t_num **stack, char *field);
void		swap(t_num **a, char ab, t_command **command_list);
void		rotate(t_num **stack, int reverse, char ab, \
	t_command **command_list);
void		ft_lstadd_front(t_num **lst, t_num *new_node);
void		push(t_num **a, t_num **b, char ab, t_command **command_list);

void		freeif_stack(t_num **list);
void		freeif_com_list(t_command **list);
void		free_everything(t_everything *everything);
void		free_num_list(t_num *num_list);
void		free_command_list(t_command *command_list);

int			ft_lstsize(t_num *lst);

void		bubble_sort(t_num **head, char *field);

int			ft_stacksize(t_num **stack);
t_num		**create_stack(int ac, char **av);
#endif
