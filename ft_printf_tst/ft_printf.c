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

int countDigits(int num)
{
    int count;

	if (num == 0)
        return 1;
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
    return count;
}
int countUnsignedDigits(unsigned int num)
{
    int count;

	count = 0;
	if (num == 0)
		return (1);
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int countBaseDigits(unsigned long num, char *base, int adress)
{
    int count;
	int len;

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
    return count;
}

int handle_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
int handle_str(char	*s)
{
	ft_putstr_fd(s, 1);
	if(!s)
		return(6);
	return (ft_strlen(s));
}
int handle_i_d(int i)
{
	ft_putnbr_fd(i, 1);
	return (countDigits(i));
}
int handle_u(unsigned int	u)
{
	ft_putunbr_fd(u, 1);
	return (countUnsignedDigits(u));
}
int handle_x(unsigned int  i, char *base, int adress)
{
	ft_putnbr_base(i, "0123456789abcdef", 0);
	return (countBaseDigits(i , base, adress));
}
int handle_X(unsigned int i, char *base, int adress)
{
	ft_putnbr_base(i, "0123456789ABCDEF", 0);
	return (countBaseDigits(i , base, adress));
}
int handle_p(void *i,char *base, int adress)
{
	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	uintptr_t n;

	n = (uintptr_t) i;
	ft_putnbr_base(n, base, adress);
	return (countBaseDigits(n , base, adress));
}

int	handle_spec(const char	*p, va_list	args)
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
		return (handle_X(va_arg(args, int), "0123456789ABCDEF", 0));
	else if (*p == 'u')
		return (handle_u(va_arg(args, unsigned int)));
	else if (*p == '%')
		return (handle_c('%'));
	else return (0);
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
