/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:24:39 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 11:25:42 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (*s1 && *s2 && *s1 == *s2 && num > 0)
	{
		s1++;
		s2++;
		num--;
	}
	if (num == 0)
		return (0);
	else
		return (*s1 - *s2);
}

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*proxy;

	proxy = ptr;
	while (num > 0)
	{
		*proxy++ = 0;
		num--;
	}
}
