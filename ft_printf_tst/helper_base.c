/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:52:46 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/06 09:52:51 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_base_digits(unsigned long num, char *base, int adress)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(base);
	if (adress)
		count += 2;
	if (num == 0)
		return (count + 1);
	while (num != 0)
	{
		num /= len;
		count++;
	}
	return (count);
}

int	handle_x(unsigned int i, char *base, int adress)
{
	ft_putnbr_base(i, "0123456789abcdef", 0);
	return (count_base_digits(i, base, adress));
}

int	handle_x_upper(unsigned int i, char *base, int adress)
{
	ft_putnbr_base(i, "0123456789ABCDEF", 0);
	return (count_base_digits(i, base, adress));
}

int	handle_p(void *i, char *base, int adress)
{
	uintptr_t	n;

	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (uintptr_t) i;
	ft_putnbr_base(n, base, adress);
	return (count_base_digits(n, base, adress));
}
