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

	if (lst == NULL)
		return (NULL);
	cpy = ft_lstnew(f(lst->content));
	if (cpy == NULL)
		return (NULL);
	start = cpy;
	while (lst->next)
	{
		cpy->next = ft_lstnew(f(lst->next->content));
		cpy = cpy->next;
		if (cpy == NULL)
			ft_lstclear(&start, del);
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
