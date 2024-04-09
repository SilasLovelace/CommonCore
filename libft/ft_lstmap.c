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

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *cpy;
    t_list  *start;
    t_list  *current;
    t_list  *todel;

    current = lst;
    cpy = ft_lstnew(f(current->content));
    if (cpy == NULL)
        return (NULL);
    start = cpy;
    while (current->next)
    {
        cpy->next = ft_lstnew(f(current->next->content));
        cpy = cpy->next;
        if (cpy == NULL)
            return (NULL);
        todel = current;
        current = current -> next;
        del(todel->content);
        free(todel);
    }
    return (start);
}
