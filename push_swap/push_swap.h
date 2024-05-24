/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:38:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/25 13:38:25 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <stdio.h>

typedef struct s_num
{
    int i_input;
    int i_sorted;
    int num;
    struct s_num *next;
    struct s_num *prev; 
}   t_num;

void check_swap(t_num **stack_a);
void check_push(t_num **stack_a, t_num **stack_b);
void check_rotate(t_num **stack_a);
void check_sort(t_num **stack_a);
void sort_assign (t_num **stack_a);

int find_cheapest(t_num **stack, int range_min, int range_max);
int	ft_biggest(t_num **stack);

t_num   *ft_lstnew(int num, int i);
t_num   *ft_lstlast(t_num *lst);
void    print_list(t_num **stack, char *field);
void    swap(t_num **a, char ab);
void    rotate(t_num **stack, int reverse, char ab);
void	ft_lstadd_front(t_num **lst, t_num *new_node);
void    push(t_num **a, t_num **b, char ab);
void    freeif_list(t_num **list);
int ft_lstsize(t_num *lst);
void    sortedInsert(t_num** head_ref, t_num* new_node);
void    sortedInsert_i(t_num** head_ref, t_num* new_node);
void    insertionSort(t_num** head, char *field);
void    assign_ordered_i(t_num** head);

int	ft_stacksize(t_num **stack);
t_num **create_stack(int ac, char **av);
#endif