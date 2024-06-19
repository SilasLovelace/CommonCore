/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:23:07 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/03 18:23:45 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		l;

	if (!size)
		return (ft_strlen(src));
	l = 0;
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
		l++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src)
	{
		src++;
		l++;
	}
	return (l);
}

/* #include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main(void)
{
char src[] = "welcome";
char dest[9];

printf("%d\n", sizeof(dest));
printf("%d\n", ft_strlcpy(dest, src, sizeof(dest)));
printf("%s\n", dest);

char src1[] = "welcome";
char dest1[] = "";

printf("%d", strlcpy(dest1, src1, sizeof(dest)));
printf("%s", dest1);

printf("%zu\n", ft_strlcpy(NULL, "asd", 0));
printf("%zu\n", strlcpy(NULL, "asd", 0));


return (0);
} */