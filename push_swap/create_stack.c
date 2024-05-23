#include "push_swap.h"

t_num **create_stack(int ac, char **av)
{
    int c;
    t_num **stack;

    c = 1;
    t_num *list = ft_lstnew(ft_atoi(av[c]), c-1);
    if (!list)
        return (NULL);
    c++;
    t_num *last = list;
    while (c < ac)
    {
        last ->next = ft_lstnew(ft_atoi(av[c]), c-1);
        if (!last -> next)
            return (freeif_list (&list), NULL);
        last->next->prev = last; 
        last = last -> next;
         c++;
    }
    stack = malloc(sizeof(t_num));
    if (!stack)
        return (freeif_list(&list), NULL);
    *stack = list;
    last -> next = list;
    list -> prev = last;
    return (stack);  
}
