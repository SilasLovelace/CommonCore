/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:06:38 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/02 18:06:41 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	l;

	if (!str1 && str2 && !len)
		return (NULL);
	if (*str2 == 0)
		return ((char *)str1);
	while (*str1 && len > 0)
	{
		p1 = (char *)str1;
		p2 = (char *)str2;
		l = 0;
		while (*p1 && *p1 == *p2 && len - l > 0)
		{
			p2++;
			p1++;
			l++;
		}
		if (*p2 == 0)
			return ((char *)str1);
		len--;
		str1++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void) {

	char one[] = "111222333";
	char two[] = "222";
	char three[] = "";
	char four[] = "333";
	char five[] = "12";
	char six[] = "";
	
	printf("%s\n", ft_strnstr(one, two, 5));
	printf("%s\n", ft_strnstr(one, two, 6));
	printf("\n");
	printf("%s\n", ft_strnstr(one, three, 2));
	printf("\n");
	printf("%s\n", ft_strnstr(one, four, 8));
	printf("%s\n", ft_strnstr(one, four, 9));
	printf("\n");
	printf("%s\n", ft_strnstr(one, five, 6));
	printf("\n");
	printf("%s\n", ft_strnstr(three, six, 2));
	printf("\n");
	printf("\n");
	printf("%s\n", strnstr(one, two, 5));
	printf("%s\n", ft_strnstr(one, two, 6));
	printf("\n");
	printf("%s\n", ft_strnstr(one, three, 2));
	printf("\n");
	printf("%s\n", ft_strnstr(one, four, 8));
	printf("%s\n", ft_strnstr(one, four, 9));
	printf("\n");
	printf("%s\n", ft_strnstr(one, five, 6));
	printf("\n");
	printf("%s\n", ft_strnstr(three, six, 2));
	printf("\n");

	return (0);
}*/
