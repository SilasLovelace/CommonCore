/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:25:17 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/04 11:38:28 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				c;

	if (num == 0)
		return (0);
	s1 = ptr1;
	s2 = ptr2;
	c = 0;
	while (s1[c] == s2[c] && c < num)
		c++;
	if (c == num)
		return (0);
	return (s1[c] - s2[c]);
}
/*
void main()
{
printf ("%d\n",ft_memcmp("abcdefghij", "abcdefgxyz", 7));
printf ("%d\n",ft_memcmp("abcdefg", "abcdefg", 7));
}*/
