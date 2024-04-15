/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:15:33 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/04 11:37:58 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				c;

	if (dest == NULL && src == NULL)
		return (dest);
	cdest = dest;
	csrc = src;
	c = 0;
	while (c < num)
	{
		cdest[c] = csrc[c];
		c++;
	}
	return (dest);
}
