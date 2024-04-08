/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:57:07 by sopperma          #+#    #+#             */
/*   Updated: 2024/02/20 15:57:09 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
/*
int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	const char *s1;
	const char *s2;
	s1 = str1;
	s2 = str2;
	
	while (*str1 && *str2 && *str1 == *str2 && num > 0)
	{
		str1++;
		str2++;
		num--;
		printf("%d\n", *str1);
		printf("%d\n", *str2);
	}
	if (num == 0)
		return (0);
	else
		return (*str1 - *str2);
}

void main()
{
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("abcdef", "abc\375xx", 5));
	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
}
*/
int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (*s1 && *s2 && *s1 == *s2 && num > 0)
	{
		s1++;
		s2++;
		num--;
	}
	if (num == 0)
		return (0);
	else
		return (*s1 - *s2);
}
/*
void main()
{
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("abcdef", "abc\375xx", 5));
	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
}
*/

/*
int main (void)
{
	char	one[0];
	char	two[0];
	char	three[] = "hello!";
	char	four[] = "helpo";

	printf("%d\n", ft_strncmp(one, two, 4));
	printf("%d\n", ft_strncmp(one, three, 6));
	printf("%d\n", ft_strncmp(three, four, 3));
	printf("%d\n", ft_strncmp(three, four, 6));
	printf("%d\n", ft_strncmp(three, one, 6));
	printf("\n");
	printf("%d\n", strncmp(one, two, 4));
	printf("%d\n", strncmp(one, three, 6));
	printf("%d\n", strncmp(three, four, 3));
	printf("%d\n", strncmp(three, four, 6));
	printf("%d\n", strncmp(three, one, 6));
	
	return (0);
}*/
