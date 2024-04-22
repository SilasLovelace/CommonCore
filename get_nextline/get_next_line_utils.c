/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:14:56 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/15 11:14:57 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*proxy;

	proxy = ptr;
	while (num > 0)
	{
		*proxy++ = 0;
		num--;
	}
}
void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*s;
	size_t			mem;

	if (SIZE_MAX / num < size)
		return (NULL);
	mem = (num * size) - 1;
	s = malloc(num * size);
	if (!s)
		return (0);
	while (mem + 1 > 0)
	{
		s[mem] = 0;
		mem--;
	}
	return ((void *)s);
}
size_t	ft_strlen(const char *str) {
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	l;
	size_t	c;
	size_t	t;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc (l);
	if (!res)
		return (0);
	c = 0;
	while (s1[c])
	{
		res[c] = s1[c];
		c++;
	}
	t = c;
	c = 0;
	while (s2[c])
	{
		res[t + c] = s2[c];
		c++;
	}
	res[t + c] = 0;
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}
