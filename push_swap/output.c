#include "push_swap.h"
#include <string.h>
int rotate_combine(t_num **stack, char ab, t_command **command_list, int bottom)
{
    t_num *top = *stack;
    while (top->i_sorted == top->prev->i_sorted + 1)
    {
        // write(1, "here", 4);
        // printf("top = %d, bot = %d\n", top->i_sorted, top->prev->i_sorted);
        rotate(stack, RR, ab, command_list);
        bottom--;
        top = *stack;
    }
    return bottom;
}

void add_command(t_command **command_list, char *command)
{
    t_command *new_command;
    t_command *element;

    if(!command)
        return;
    new_command = malloc(sizeof(t_command));
    if (!new_command)
        return ;
    new_command ->command = ft_strdup(command);
    if (!new_command ->command)
        return (free(new_command));
    new_command -> next = NULL;
    if(!command_list || !(*command_list))
    {
        *command_list = new_command;
    }
    else
    {
        element = *command_list;
        while (element ->next)
        {
            element = element -> next;
        }
        element ->next = new_command;
    }    
}
void print_command_list(t_command **command_list)
{
    t_command *element;

     if(!command_list || !(*command_list))
        return;
    element = *command_list;
    while (element)
    {
        write(1, element->command, ft_strlen(element->command));
        write(1, "\n", 1);
        element = element -> next;
    }
}
int num_instructions(t_command **command_list)
{
    t_command *element;
    int c;

    c = 0;
    if(!command_list || !(*command_list))
        return (0);
    element = *command_list;
    while (element)
    {
        c++;
        element = element -> next;
    }
    return (c);
}
void trim_command_list(t_command **command_list)
{
    t_command *element;
    t_command *prev;
    t_command *to_free;

    if (!command_list || !(*command_list))
        return;

    element = *command_list;
    prev = NULL;

    while (element && element->next)
    {
        if ((strcmp(element->command, "ra") == 0 && strcmp(element->next->command, "rb") == 0) ||
            (strcmp(element->command, "rb") == 0 && strcmp(element->next->command, "ra") == 0))
        {
            element->command = ft_strdup("rr");
            to_free = element->next;
            element->next = element->next->next;
            free(to_free->command);
            free(to_free);
        }
        else if ((strcmp(element->command, "rra") == 0 && strcmp(element->next->command, "rrb") == 0) ||
                 (strcmp(element->command, "rrb") == 0 && strcmp(element->next->command, "rra") == 0))
        {
            element->command = ft_strdup("rrr");
            to_free = element->next;
            element->next = element->next->next;
            free(to_free->command);
            free(to_free);
        }
        else
        {
            prev = element;
            element = element->next;
        }
    }
}