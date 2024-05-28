#include "push_swap.h"

// Function to swap the num field of two t_num nodes
static void bubble_swap(t_num *a, t_num *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;

	temp = a->i_input;
	a->i_input = b->i_input;
	b->i_input = temp;

	temp = a->i_sorted;
	a->i_sorted = b->i_sorted;
	b->i_sorted = temp;
}

static int check_cond(t_num *ptr, char *field)
{
    if(ft_strcmp(field, "num"))
        return (ptr->num > ptr->next->num);
    else if(ft_strcmp(field, "input"))
        return (ptr->i_sorted > ptr->next->i_sorted);
    else
        return (-1);
}

static t_num	**create_link_stack(t_num *first, t_num *last)
{
	t_num	**stack;

	stack = malloc(sizeof(t_num));
	if (!stack)
		return (freeif_list(&first), NULL);
	*stack = first;
	last -> next = first;
	first -> prev = last;
	return (stack);
}

// Function to implement bubble sort on the linked list
void bubble_sort(t_num **head, char *field)
{
	if (head == NULL || *head == NULL)
		return;
	int swapped;
	t_num *ptr;
	t_num *lptr;

    swapped = 1;
    lptr = NULL;
	while (swapped)
    {
		swapped = 0;
		ptr = *head;
		while (ptr->next != lptr)
        {
            if(check_cond(ptr, field) < 0)
                return ;
			if (check_cond(ptr, field))
            {
				bubble_swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
    if(check_cond(ptr, "input"))
        head = create_link_stack(*head, lptr);
}
