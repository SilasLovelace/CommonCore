/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:07:03 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 14:07:04 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	c;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	else if (str_len - start < len)
		len = str_len - start;
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	c = 0;
	if (len)
	{
		while (s[start + c] && c < len)
		{
			dup[c] = s[start + c];
			c++;
		}
	}
	dup[c] = 0;
	return (dup);
}
