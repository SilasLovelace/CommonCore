#include "push_swap.h"

t_num	*ft_lstnew(int num, int i)
{
	t_num	*new;

	new = (t_num *)malloc(sizeof(t_num));
	if (new == NULL)
		return (NULL);
    new->i_input = i;
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_stacksize(t_num **stack)
{
	int		c;
	t_num	*current;

	c = 0;
	current = *stack;
	while (current)
	{
		c++;
		current = current->next;
		if (current == (*stack))
			break ;
	}
	return (c);
}

int	ft_biggest(t_num **stack)
{
	int		biggest;
	t_num	*current;

	if (!stack || !(*stack))
		return -1;
	biggest = 0;
	current = *stack;
	while (current)
	{
		if (current->i_sorted > biggest)
			biggest = current -> i_sorted;
		current = current->next;
		if (current == (*stack))
			break ;
	}
	return (biggest);
}