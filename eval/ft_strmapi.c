/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:42:58 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 18:43:00 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	size_t	len;
	size_t	c;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	c = 0;
	while (c < len)
	{
		dup[c] = f(c, s[c]);
		c++;
	}
	dup[c] = 0;
	return (dup);
}
