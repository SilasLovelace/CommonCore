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

	dlen = strlen(dest);
	slen = strlen(src);
	while (*dest && size > 1)
	{
		dest++;
		size--;
	}
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	if (size > 0)
	{
		*dest = '\0';
	}
	return (dlen + slen);
}
/*
int main(void)
{
	char one[] = "1";
	char two[] = "22";
	printf("%d\n", ft_strlcat(one, two, 2));
	printf("%s\n", one);
	printf("%d\n", ft_strlcat(one, two, 0));
	printf("%s\n", one);
	
	return (0);
}
*/
