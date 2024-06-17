/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:48:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/17 14:33:55 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *ptr)
{
	long		n;
	int			sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		if (n > (long)INT_MAX + (long)(sign == -1))
			return (0);
		str++;
	}
	*ptr = (n * sign);
	return (1);
}
/*
#include <unistd.h>
int	main(void)
{
	printf("%d\n", atoi("92233720368547759"));
	printf("%d\n", ft_atoi("92233720368547759"));
	return (0);
}
*/