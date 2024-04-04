/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:13:42 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 12:13:43 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*found;

	found = 0;
	while (*str)
	{
		if (*str == c)
			found = (char *)str;
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (found);
}
