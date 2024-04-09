/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:39:02 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/09 10:39:04 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int c;
    t_list  *next;

    c = 0;
    next = lst->next;
    while (next)
    {
        c++;
        next = next->next;
    }
    return (c);
}
