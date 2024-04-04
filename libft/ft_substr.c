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
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	c;

	dup = malloc(len + 1);
	if (!dup)
		return (0);
	c = 0;
	while (s[start + c] && c < len)
	{
		dup[c] = s[start + c];
		c++;
	}
	dup[c] = 0;
	return (dup);
}
