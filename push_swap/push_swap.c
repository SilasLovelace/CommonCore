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

    // printf("\nstacksize: %d, chunks: %d,  middle index: %d, upper limit: %d, lower limit: %d", stack_size, chunks, middle, middle + chunk_size, middle -chunk_size);
    // printf("\nrotate direction %d", find_cheapest(stack_a, 2, 2));
   while (find_cheapest(stack_a, lower_limit, upper_limit) > -1)
    {
        while (find_cheapest(stack_a, lower_limit, upper_limit) > -1)
        { 
            if ((*stack_a)->i_sorted >=  lower_limit && (*stack_a)->i_sorted <=  upper_limit)
                break;
            rotate(stack_a,find_cheapest(stack_a, lower_limit, upper_limit), 'a');
        }
        push(stack_a, stack_b);
        if((*stack_b)->i_sorted < middle)
        {
            // printf("rot_b\n");
            rotate(stack_b, 0, 'b');
        }
        // print_list(stack_a, "num");
        // print_list(stack_b, "num");
        if (find_cheapest(stack_a, lower_limit, upper_limit) < 0)
        {
            lower_limit -= chunk_size;
            upper_limit += chunk_size;
        }
    }
    // print_list(stack_b, "sorted");
    return (freeif_list (stack_a), freeif_list (stack_b),0);
}