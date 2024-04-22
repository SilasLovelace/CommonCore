/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:46:32 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 14:46:33 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
/*
#include <stdio.h>
#include <limits.h>
int main ()
{
	char s[] = "abc";
	printf("%s\n", reverse (s, 3));

	int num = INT_MIN;
	 printf("digits: %d\n", digits(num));
        printf("Integer: %d, String: %s\n", num, ft_itoa(num));
    return 0;
}*/
