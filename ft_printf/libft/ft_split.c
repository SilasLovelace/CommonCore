/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:16:53 by sopperma          #+#    #+#             */
/*   Updated: 2024/03/04 15:18:11 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_seperator(const char *str, char charset)
{
	if (charset == *str)
		return (1);
	return (0);
}

static int	countwords(const char *str, char charset)
{
	int	c;

	if (!charset && !(*str))
		return (0);
	else if (!charset)
		return (1);
	c = 0;
	while (*str)
	{
		if (is_seperator(str, charset))
			str ++;
		else
		{
			c++;
			while (!is_seperator(str, charset) && *str)
				str++;
		}
	}
	return (c);
}

static char	*cpystr(const char *str, char charset)
{
	char	*cpy;
	char	*start;
	int		c;
	int		strlen;

	strlen = 0;
	c = 0;
	start = (char *)str;
	while (*str && !is_seperator(str, charset))
	{
		str++;
		strlen++;
	}
	str = start;
	cpy = malloc ((strlen + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (c < strlen)
	{
		cpy[c] = str[c];
		c++;
	}
	cpy[c] = '\0';
	return (cpy);
}

static void	ft_free(char **arr, size_t w)
{
	while (w + 1 > 0)
	{
		free(arr[w]);
		w--;
	}
	free(arr);
	return ;
}

char	**ft_split(const char *str, char charset)
{
	char	**arr;
	int		c;
	int		w;

	if (!str)
		return (NULL);
	w = 0;
	c = countwords(str, charset);
	arr = malloc((c + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[c] = NULL;
	while (w < c)
	{
		while (*str && is_seperator(str, charset))
			str++;
		arr[w] = cpystr(str, charset);
		if (arr[w] == NULL)
			return (ft_free(arr, (w - 1)), NULL);
		w++;
		while (*str && !is_seperator(str, charset))
			str++;
	}
	return (arr);
}
/*
#include <stdio.h>
#include <unistd.h>
 int main (int argc, char **argv)
{
	//printf("%d\n", argc);
	printf("%d\n", countwords(argv[1], argv[2][0]));
	char	**arr = ft_split(argv[1], argv[2][0]);

	int i = 0;
	while (arr[i])
	{
		printf("[%s]", arr[i]);
		i++;
	}
	printf("[%s]\n", arr[i]);
} */
/* 
void main(int argc, char **argv)
{
	//char	**arr = ft_split("xxxxxxxxhello!",'x');
	char **arr =ft_split(argv[1], argv[2][0]);
		int i = 0;
	while (arr[i])
	{
		printf("[%s]", arr[i]);
		i++;
	}
}
 */

/*void main(int argc, char **argv)
{
char **arr = ft_split("lorem ipsum dolor sit amet, \
consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');

		int i = 0;
	while (arr[i])
	{
		printf("[%s]", arr[i]);
		i++;
	}
}*/
