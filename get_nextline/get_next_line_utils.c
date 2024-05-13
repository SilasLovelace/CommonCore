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

void	freeif(char **p)
{
	if (p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

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

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	c;
	size_t	t;

	if (!s1 && !s2)
		return (NULL);
	res = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	c = 0;
	t = 0;
	while (s1 && s1[c])
	{
		res[c] = s1[c];
		c++;
	}
	t = c;
	c = 0;
	while (s2 && s2[c])
	{
		res[t + c] = s2[c];
		c++;
	}
	res[t + c] = 0;
	return (res);
}
