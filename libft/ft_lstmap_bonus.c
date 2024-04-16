/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:40:22 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/09 10:40:23 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*start;
	void	*var;

	if (!lst || !f || !del)
		return (NULL);
	var = f(lst->content);
	cpy = ft_lstnew(var);
	if (cpy == NULL)
		return (free(var), NULL);
	start = cpy;
	while (lst->next)
	{
		var = f(lst->next->content);
		cpy->next = ft_lstnew(var);
		cpy = cpy->next;
		if (cpy == NULL)
		{
			free(var);
			ft_lstclear(&start, del);
			break ;
		}
		lst = lst -> next;
	}
	return (start);
}

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	
	new_lst = NULL;
	while (lst && f && del)
	{
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
			ft_lstclear(&new_lst, del);
		else
		{
			ft_lstadd_back(&new_lst, current);
			lst = lst->next;
		}
	}
	return (new_lst);
} */
