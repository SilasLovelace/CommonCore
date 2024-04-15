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
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*s;
	size_t			mem;

	mem = (num * size) - 1;
	s = malloc(num * size);
	if (!s)
		return (0);
	if (num * size == 0)
		return (s);
	while (mem + 1 > 0)
	{
		s[mem] = 0;
		mem--;
	}
	return (s);
}
