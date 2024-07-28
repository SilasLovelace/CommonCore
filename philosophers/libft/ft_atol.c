/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:48:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/20 16:53:00 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long		n;
	int			sign;
	long		over;

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
	printf("%d\n", atol("392233720368547759"));
	printf("%d\n", ft_atol("292233720368547759"));
	return (0);
}
*/