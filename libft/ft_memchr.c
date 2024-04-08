/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:18:56 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/04 11:38:15 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*scan;
	size_t				c;

	c = 0;
	scan = ptr;
	while (c < num)
	{
		if (scan[c] == (unsigned char)value)
			return ((void *)(scan + c));
		c++;
	}
	return (0);
}
/*
void main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%p\n", (char *)memchr(tab, -1, 7));
	printf("%p\n", (char *)ft_memchr(tab, -1, 7));
}
*/