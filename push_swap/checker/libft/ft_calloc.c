/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:41:15 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 12:41:17 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*s;
	size_t			mem;

	if (num && SIZE_MAX / num < size)
		return (NULL);
	mem = (num * size) - 1;
	s = malloc(num * size);
	if (!s)
		return (NULL);
	while (mem + 1 > 0)
	{
		s[mem] = 0;
		mem--;
	}
	return ((void *)s);
}

/* void main()
#include <stdio.h>

{ 
	void *str = ft_calloc(0, 0);
	void *s = calloc(0, 0);
	printf("%p", str);
	printf("%p", s);
} */