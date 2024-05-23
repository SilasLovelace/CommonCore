#include "push_swap.h"

static void insert_node(t_num *push_node, t_num **b)
{
    t_num *tail;

    if (b && *b)
    {
        tail = (*b)->prev;
        push_node->next = *b;
        push_node->prev = tail;
        tail->next = push_node;
        (*b)->prev = push_node;
        *b = push_node;
    }
    else
    {
        push_node->next = push_node;
        push_node->prev = push_node;
        *b = push_node;   
    }
}

void push(t_num **a, t_num **b)
{
    t_num *push_node;
    t_num *tail;

    if (!a || !*a)
        return;
    push_node = *a;
    if ((*a)->next == *a)
        *a = NULL;
    else
    {
        tail = (*a)->prev;
        *a = (*a)->next;
        (*a)->prev = tail;
        tail->next = *a;
    }
    insert_node(push_node, b);
    write(1, "pb\n", 3);
}

void swap(t_num **a)
{
    t_num *first_node;
    t_num *second_node;

    if (!a || !(*a))
        return ;
    first_node = *a;
    if (first_node -> next != first_node)
    {
        second_node = first_node->next;

        // Case where there are only two nodes
        if (second_node->next == first_node)
        {
            first_node->next = second_node;
            first_node->prev = second_node;
            second_node->next = first_node;
            second_node->prev = first_node;
        }
        else
        {
            first_node->next = second_node->next;
            first_node->next->prev = first_node;
            second_node->next = first_node;
            second_node->prev = first_node->prev;
            first_node->prev->next = second_node; // Update the prev of the head to point to the new head
            first_node->prev = second_node;
        }
        *a = second_node;
    }
}
void printcommand(char *command, char ab)
{
    // printf("command print %s\n", command);
    // printf("letter print %c\n", ab);
    // printf("command cond r %d\n", ft_strncmp(command, "r", ft_strlen(command)));
    // printf("command cond rr %d\n", ft_strncmp(command, "rr", ft_strlen(command)));
    if (!ft_strncmp(command, "r", ft_strlen(command)))
    {
        // printf("cond %d\n", ab == 'a');
        if(ab == 'a')
            write(1, "ra\n", 3);
        else 
            write(1, "rb\n", 3);
    }
    else if (!ft_strncmp(command, "rr", ft_strlen(command)))
    {
        if(ab == 'a')
            write(1, "rra\n", 4);
        else 
            write(1, "rrb\n", 4);
    }  
}
void rotate(t_num **stack, int reverse, char ab)
{
    // printf("char %c\n", ab);
    if (reverse < 0)
        return;
    if (reverse)
    {
        *stack =(*stack) -> prev;
        printcommand("rr", ab);
    } 
    else
    {
        *stack = (*stack) -> next;
        printcommand("r", ab);
    }
}