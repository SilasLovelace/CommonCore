/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:10:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 19:10:20 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;
	long	num;

	num = n;
	if (!num)
	{
		write (fd, "0", 1);
		return ;
	}
	if (num >= 10)
	{
		ft_putunbr_fd(num / 10, fd);
	}
	c = num % 10 + '0';
	write (fd, &c, 1);
}
/*
#include <limits.h>
int main()
{
	ft_putunbr_fd(UINT_MAX, 1);
}
*/
