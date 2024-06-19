/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:19:32 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/19 18:02:04 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	joinlen(const char *s1, const char *s2)
{
	size_t	len;

	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	c;
	size_t	t;

	if (!s1 && !s2)
		return (NULL);
	res = malloc (joinlen(s1, s2) + 1);
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

/* #include <stdio.h>
int main()
{
	printf("%s\n", ft_strjoin("abc", ""));
	printf("%s\n", ft_strjoin("", ""));
	printf("%s\n", ft_strjoin("abc", NULL));
	printf("%s\n", ft_strjoin(NULL, "abc"));
} */