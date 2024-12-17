/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:18:17 by sopperma          #+#    #+#             */
/*   Updated: 2024/10/22 11:24:53 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static int	digits(long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		digit;
	long	num;

	num = n;
	digit = digits(n);
	a = malloc(digit + 1);
	if (!a)
		return (NULL);
	a[digit] = 0;
	if (num < 0)
	{
		num = -num;
		digit--;
		*a++ = '-';
	}
	while (0 < digit--)
	{
		a[digit] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		a--;
	return (a);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
