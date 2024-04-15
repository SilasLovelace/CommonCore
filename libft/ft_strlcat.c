/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:00:13 by sopperma          #+#    #+#             */
/*   Updated: 2024/02/20 20:00:17 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	s;
	size_t	d;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	s = 0;
	d = dlen;
	if (size <= dlen)
		return (slen + size);
	if (size > 0)
	{
		while (src[s] && d < size - 1)
		{
			dest[d] = src[s];
			s++;
			d++;
		}
	}
	dest[d] = 0;
	return (dlen + slen);
}
