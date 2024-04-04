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
	unsigned char			*d;
	const unsigned char		*s;
	size_t					c;

	s = src;
	d = dest;
	c = 0;
	if (src < dest && src + num > dest)
	{
		c = num - 1;
		while (c + 1 > 0)
		{
			d[c] = s[c];
			c--;
		}
	}
	else
	{
		while (c < num)
		{
			d[c] = s[c];
			c++;
		}
	}
	return (dest);
}
