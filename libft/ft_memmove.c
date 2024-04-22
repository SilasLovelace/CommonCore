/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:20:20 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 18:39:03 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t					c;

	c = 0;
	if ((dest == NULL && src == NULL) || num == 0)
		return (dest);
	if (src < dest && src + num > dest)
	{
		c = num;
		while (c > 0)
		{
			c--;
			((char *)dest)[c] = ((char *)src)[c];
		}
	}
	else
	{
		while (c < num)
		{
			((char *)dest)[c] = ((char *)src)[c];
			c++;
		}
	}
	return (dest);
}
