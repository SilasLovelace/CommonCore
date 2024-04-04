/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:19:25 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 14:19:27 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	isset(const char *s, char const *set)
{
	while (*set)
	{
		if (*set == *s)
			return (1);
		set++;
	}
	return (0);
}

int	issetend(const char *s, char const *set)
{
	while (*s)
	{
		if (!(isset(s, set)))
			return (0);
		s++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	char	*start;
	size_t	l;
	size_t	c;

	c = 0;
	l = 0;
	while (isset(s1, set))
		s1++;
	start = (char *)s1;
	while (*s1 && !(issetend(s1, set)))
	{
		s1++;
		l++;
	}
	dup = malloc(l + 1);
	if (!dup)
		return (0);
	while (start[c] && c < l)
	{
		dup[c] = start[c];
		c++;
	}
	dup[c] = 0;
	return (dup);
}
