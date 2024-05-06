/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_i_d_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:52:59 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/06 09:53:03 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	count_unsigned_digits(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	handle_i_d(int i)
{
	ft_putnbr_fd(i, 1);
	return (count_digits(i));
}

int	handle_u(unsigned int u)
{
	ft_putunbr_fd(u, 1);
	return (count_unsigned_digits(u));
}
