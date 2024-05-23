#include "push_swap.h"

int find_cheapest(t_num **stack, int range_min, int range_max)
{
    t_num *current;
    int rotate_price;
    int rev_rotate_price;

    if (!stack || !(*stack))
        return -1;
    current = *stack;
    rotate_price = 0;
    rev_rotate_price = 0;
    while(current)
    {
        if (current ->i_sorted >= range_min && current ->i_sorted <= range_max)
            break ;
        rotate_price++;
        current = current ->next;
        if (current == *stack)
            return -1;
    }
    current = *stack;
    while(current)
    {
        if (current ->i_sorted >= range_min && current ->i_sorted <= range_max )
            break ;
        rev_rotate_price++;
        current = current ->prev;
        if (current == *stack)
            return -1;
    }
    // printf("\nrotate_price %d, rev_rotate_price %d", rotate_price, rev_rotate_price);
    if (rotate_price < rev_rotate_price)
        return 0;
    return 1;
}

void sort(t_num **a, t_num **b)
{
    t_num *tmp = NULL;
    tmp ->num = (*a) -> num + (*b) ->num;
}