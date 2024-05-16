/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:04:40 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/13 10:04:41 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft/libft.h"



void pa(int *a, int *b)
{
    
}
void pb(int *a, int *b)
{
    
}
void rx(int *a)
{
    
}
void rr(int *a, int *b)
{
   rx (a);
   rx (b);
}
void rrx(int *a)
{
    
}
void rrr(int *a, int *b)
{
    rrx(a);
    rrx(b);
}


typedef struct s_num
{
    int i;
    int num;
    struct s_num *next;
}   t_num;

t_num	*ft_lstnew(int num, int i)
{
	t_num	*new;

	new = (t_num *)malloc(sizeof(t_num));
	if (new == NULL)
		return (NULL);
    new->i = i;
	new->num = num;
	new->next = NULL;
	return (new);
}
t_num	*ft_lstlast(t_num *lst)
{
	t_num	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}
void print_list(t_num **stack)
{  
    t_num *list;

    if(!stack || !*stack)
        return ;    
    list = *stack;
    while (list)
    {
        ft_putnbr_fd(list -> num, 1);
        write(1, " ", 1);
        list = list -> next;
    }
    write(1, "\n", 1);
}
void print_list_i(t_num **stack)
{  
    t_num *list;

    if(!stack || !*stack)
        return ;    
    list = *stack;
    while (list)
    {
        ft_putnbr_fd(list -> i, 1);
        write(1, " ", 1);
        list = list -> next;
    }
    write(1, "\n", 1);
}

void swap(t_num **a)
{
    t_num *second;
    t_num *start;

    if (!a || !(*a))
        return ;
    start = *a;
    if (start -> next)
    {
        second = start ->next;
        start ->next = start ->next ->next;
        second ->next = start;
        *a = second;
    }
}
void rotate(t_num **stack, int reverse)
{
    t_num *first;
    t_num *new_first;

    if (!stack || !*stack || !(*stack) ->next)
        return ;
    if (reverse)
    {
        new_first = (*stack) -> next;
        ft_lstlast(*stack) -> next = *stack;
        (*stack) -> next = NULL;
        *stack = new_first;
    }
    else if (!reverse)
    {
        first = *stack;
        while (first -> next -> next)
            first = first ->next;
        new_first = first ->next;
        first -> next = NULL;
        new_first ->next = *stack;
        *stack = new_first;
    }
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void push(t_num **a, t_num **b)
{
    t_num *start;

    if (!a || !*a)
        return ;
    start = *a;
    *a = (*a) -> next;
    start ->next = NULL;
    if (b && *b)
    {
        start ->next = *b;
        *b = start;
    }
    else
        *b = start;
}

void freeif_list(t_num **list)
{
    t_num *current;
    t_num *next;

    if (!list || !*list)
        return ;
    current = *list;
    while (current)
    {
        next = current -> next;
        free(current);
        current = next;
    }
}
int	ft_lstsize(t_num *lst)
{
	int		c;
	t_num	*current;

	c = 0;
	current = lst;
	while (current)
	{
		c++;
		current = current->next;
	}
	return (c);
}
int main (int ac, char **av)
{
    int c;

    c = 1;
    if (ac < 2)
        return (0);
    t_num *list_a = ft_lstnew(ft_atoi(av[c]), c-1);
    if (!list_a)
        return (0);
    c++;
    t_num *last = list_a;
    while (c < ac)
    {
        last ->next = ft_lstnew(ft_atoi(av[c]), c-1);
        if (!last -> next)
            return (freeif_list (&list_a), 0);
        c++;
        last = last -> next;
    }
    t_num **stack_a = malloc(sizeof(t_num));
    if (!stack_a)
        return (0);
    *stack_a = list_a;
    t_num **stack_b = malloc(sizeof(t_num));
    if (!stack_b)
        return (freeif_list (stack_a), 0);
    *stack_b = NULL;

    int n = 5;
    int half_size = ft_lstsize(*stack_a);
    int offset = half_size/n;

    print_list(stack_a);
    print_list_i(stack_a);
    /* swap(stack_a);
    print_list(stack_a);
    swap(stack_a);
    print_list(stack_a); */
    /* rotate(stack_a, 1);
    print_list(stack_a); */
   /*  rotate(stack_a, 1);
    print_list(stack_a); */
    /* rotate(stack_a, 0);
    print_list(stack_a); */
    /* print_list(stack_a);
    push(stack_a, stack_b);
    print_list(stack_a);
    print_list(stack_b);
    push(stack_a, stack_b);
    print_list(stack_a);
    print_list(stack_b); */
    return (freeif_list (stack_a), freeif_list (stack_b), free(stack_a),  free(stack_b),0);
}