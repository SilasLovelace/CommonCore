/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:48:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/02/21 18:48:28 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		sign;
	long	over;

	over = 0;
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
		if (over != (over * 10 + *str - '0') / 10)
			return ((sign >= 0) * -1);
		over = over * 10 + *str - '0';
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
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