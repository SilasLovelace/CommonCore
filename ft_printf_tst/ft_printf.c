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

#include "ft_printf.h"
#include "libft/libft.h"

static int	handle_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	handle_str(char	*s)
{
	ft_putstr_fd(s, 1);
	if (!s)
		return (6);
	return (ft_strlen(s));
}

static int	handle_spec(const char	*p, va_list	args)
{
	if (*p == 'c')
		return (handle_c(va_arg(args, int)));
	else if (*p == 's')
		return (handle_str(va_arg(args, char *)));
	else if (*p == 'd')
		return (handle_i_d(va_arg(args, int)));
	else if (*p == 'i')
		return (handle_i_d(va_arg(args, int)));
	else if (*p == 'p')
		return (handle_p(va_arg(args, void *), "0123456789abcdef", 1));
	else if (*p == 'x')
		return (handle_x(va_arg(args, int), "0123456789abcdef", 0));
	else if (*p == 'X')
		return (handle_x_upper(va_arg(args, int), "0123456789ABCDEF", 0));
	else if (*p == 'u')
		return (handle_u(va_arg(args, unsigned int)));
	else if (*p == '%')
		return (handle_c('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += handle_spec(s++, args);
		}
		else
		{
			count++;
			ft_putchar_fd(*s++, 1);
		}
	}
	va_end(args);
	return (count);
}
