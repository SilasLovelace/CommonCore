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

#include"ft_printf.h"
#include"libft.h"

void handle_spec(const char	*p, va_list	args)
{
	if (*p == 'c')
		ft_putchar_fd(va_arg(args, int*), 1);
	else if (*p == 's')
		ft_putstr_fd(va_arg(args, char*), 1);
	//else if (*p == 'p')
	else if (*p == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*p == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	//else if (*p == 'u')
	//else if (*p == 'x')
	//else if (*p == 'X')
	else if (*p == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *s, ...)
{
	int	count;
	va_list	args;
	const char *p = s;
	va_start(args, p);
	
	count = 0;
	while (*p)
	{
		count++;
		if (*p == '%')
		{
			p++;
			handle_spec(p++, args);
		}
		else 
			ft_putchar_fd(*p++, 1);
	}
	va_end(args);
	return (count);
}

#include <limits.h>

int main ()
{
	char* t = "hello";
	int i = INT_MIN;
	ft_printf("test %s %c %i %d %%", t, t[0], i, i);
	return (0);
}
