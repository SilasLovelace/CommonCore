/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:52:50 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 12:52:52 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	c;
	char	*dup;

	c = 0;
	while (str[c])
		c++;
	dup = malloc(c + 1);
	if (!dup)
		return (0);
	c = 0;
	while (str[c])
	{
		dup[c] = str[c];
		c++;
	}
	dup[c] = 0;
	return (dup);
}
