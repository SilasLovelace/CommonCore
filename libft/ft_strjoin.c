/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:19:32 by sopperma          #+#    #+#             */
/*   Updated: 2024/02/26 19:19:35 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && len <= 2147483647)
	{
		len++;
		str++;
	}
	return (len);
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
	res[l] = 0;
	return (res);
}
/*
int main()
{
	char *s[] = {"1234", "456"};
	char *x = "---";

	printf("%ld\n", arlen(s, 2));
	printf("%s\n", ft_strjoin(2, s, x));
}*/
