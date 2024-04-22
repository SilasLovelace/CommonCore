/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:45:59 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 11:46:01 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if(!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
/*
int main()
{	
	printf("%p\n",ft_strchr("teste",'e'));
	printf("%p\n",strchr("teste",'e'));
	printf("%p\n",ft_strchr("teste",'\0'));
	printf("%p\n",strchr("teste",'\0'));
}
*/