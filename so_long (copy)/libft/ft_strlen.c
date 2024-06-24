/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:25:19 by sopperma          #+#    #+#             */
/*   Updated: 2024/02/21 18:25:22 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
/*
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
int main() {
    printf("Maximum value of int: %u\n", UINT_MAX);
    printf("Maximum value of int: %d\n", INT_MAX);
    return 0;
}
*/
