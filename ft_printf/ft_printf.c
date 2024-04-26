/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:42:34 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/25 13:42:36 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	handle_spec(const char	*p, va_list	args)
{
	if (*p == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*p == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*p == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*p == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*p == 'p')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 1);
	else if (*p == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 0);
	else if (*p == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0);
	else if (*p == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (*p == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		count++;
		if (*s == '%')
		{
			s++;
			handle_spec(s++, args);
		}
		else
			ft_putchar_fd(*s++, 1);
	}
	va_end(args);
	return (count);
}
