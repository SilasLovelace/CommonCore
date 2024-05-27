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
#include "push_swap.h"

int main (int ac, char **av)
{
    if (ac < 2)
        return (0);
    t_num **stack_a = create_stack(ac, av);
    if (!stack_a)
        return (freeif_list (stack_a), 0);
    t_num **stack_b = malloc(sizeof(t_num));
    if (!stack_b)
        return (freeif_list (stack_a), 0);
    *stack_b = NULL;

    t_command **command_list = malloc (sizeof(t_command));
    if (!command_list)
        return (freeif_list (stack_a), freeif_list (stack_b), 0);

    // check_sort(stack_a);
    // check_swap(stack_a);
    // check_push(stack_a, stack_b);
    // check_rotate(stack_a);
    // printf("\nStacksize: %d", ft_stacksize(stack_a) ); 
    sort_assign(stack_a);

    int stack_size = ft_stacksize(stack_a);
    int chunks;
    int middle;
    int chunk_size;
    int upper_limit;
    int lower_limit;
    middle = stack_size/2;
    
   

    if (stack_size <= 10)
        chunks = 5;
    else if (stack_size <= 150)
        chunks = 8;
    else
        chunks = 18;
    chunk_size = ft_stacksize(stack_a) / chunks;

    upper_limit = middle + chunk_size;
    lower_limit = middle - chunk_size;

    // first part
   while (find_cheapest(stack_a, lower_limit, upper_limit) > -1)
    {
        while (find_cheapest(stack_a, lower_limit, upper_limit) > -1)
        { 
            if ((*stack_a)->i_sorted >=  lower_limit && (*stack_a)->i_sorted <=  upper_limit)
                break;
            rotate(stack_a,find_cheapest(stack_a, lower_limit, upper_limit), 'a', command_list);
        }
        push(stack_a, stack_b, 'b', command_list);
        if((*stack_b)->i_sorted < middle)
            rotate(stack_b, 0, 'b', command_list);
        if (find_cheapest(stack_a, lower_limit, middle) < 0)
            lower_limit -= chunk_size;
        if (find_cheapest(stack_a, middle, upper_limit) < 0)
            upper_limit += chunk_size;
    
    }
    // second part
    int biggest = ft_biggest(stack_b);
    while (!((*stack_b)->i_sorted == biggest))
        rotate(stack_b, find_cheapest(stack_b, biggest, biggest), 'b', command_list);
    int bottom = 0;
    while (ft_biggest(stack_b) >= 0)
    {  
        if (!(ft_stacksize(stack_a)) || (*stack_b)->i_sorted == (*stack_a)->i_sorted -1)
        {
            push(stack_b, stack_a, 'a', command_list);
            if (bottom)
                bottom = rotate_combine(stack_a, 'a', command_list, bottom);
        }
        else if ((*stack_b)->i_sorted > (*stack_a)->prev->i_sorted || !bottom)
        {
            push(stack_b, stack_a, 'a', command_list);
            rotate(stack_a, 0, 'a', command_list);
            bottom++;
        }
        else
            rotate(stack_b, find_cheapest(stack_b, (*stack_a)->prev->i_sorted + 1, (*stack_a)->i_sorted - 1), 'b', command_list);
    }
    // printf("before trim %d\n", num_instructions(command_list));
    trim_command_list(command_list);
    // printf("after trim %d\n", num_instructions(command_list));
    print_command_list(command_list);
    // print_list(stack_a, "sorted");
    return (freeif_list (stack_a), freeif_list (stack_b),0);
}