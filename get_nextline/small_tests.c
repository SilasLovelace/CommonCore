#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>	

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


size_t	ft_strlen(const char *str)
{
    if (str == NULL)
        return 0;
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	l;
	size_t	c;
	size_t	t;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc (l);
	if (!res)
		return (0);
	c = 0;
    if (s1 != NULL)
    {
        while (s1[c])
	    {
		res[c] = s1[c];
		c++;
	    }   
    }
	t = c;
	c = 0;
    if (s2 != NULL)
    {
	while (s2[c])
	{
		res[t + c] = s2[c];
		c++;
	}
    }
	res[t + c] = 0;
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	c;
	char	*dup;

	c = 0;
	while (str[c])
		c++;
	dup = malloc(c + 1);
	if (!dup)
		return (0);
	c = 0;
	while (str[c])
	{
		dup[c] = str[c];
		c++;
	}
	dup[c] = 0;
	return (dup);
}


void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				c;

	if (dest == NULL && src == NULL)
		return (dest);
	cdest = dest;
	csrc = src;
	c = 0;
	while (c < num)
	{
		cdest[c] = csrc[c];
		c++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t					c;

	c = 0;
	if ((dest == NULL && src == NULL) || num == 0)
		return (dest);
	if (src < dest && src + num > dest)
	{
		c = num - 1;
		while (c + 1 > 0)
		{
			((char *)dest)[c] = ((char *)src)[c];
			c--;
		}
	}
	else
	{
		while (c < num)
		{
			((char *)dest)[c] = ((char *)src)[c];
			c++;
		}
	}
	return (dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*s;
	size_t			mem;

	if (SIZE_MAX / num < size)
		return (NULL);
	mem = (num * size) - 1;
	s = malloc(num * size);
	if (!s)
		return (0);
	while (mem + 1 > 0)
	{
		s[mem] = 0;
		mem--;
	}
	return ((void *)s);
}

char *get_front(char *buffer, char delim, char front_back)
{
	char	*res;
	char	*delim_pos;

	if (!buffer || !*buffer)
        return NULL;
	delim_pos = ft_strchr(buffer, delim);
	if (!delim_pos)
        return ft_strdup(buffer);
	if (front_back == 0)
	{
		res = calloc((delim_pos - buffer + 2), sizeof(char));
		if(!res)
            return NULL;
		res = ft_memcpy(res, buffer ,delim_pos - buffer + 1);
		return (res);
	}
	delim_pos++;
	res = calloc(ft_strlen(delim_pos) + 1, sizeof(char));
	if(!res)
        return NULL;
	res = ft_memcpy(res, delim_pos ,ft_strlen(delim_pos));
		return (res);
}

//memmove causes errors
char	*get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE+1];
    char    *line;
    char    *temp;
    int bytes_read;

    line = NULL;
    temp = NULL;
    bytes_read = 1;
    if (buffer[0] && ft_strchr(buffer, '\n'))
	{
		 line = ft_strjoin(line, get_front(buffer, '\n', 1));
		 ft_memmove(buffer, (ft_strchr(buffer, '\n') + 1), ft_strlen((ft_strchr(buffer, '\n') + 1)) +1);
	}
      
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
                buffer[bytes_read] = '\0';
        if(ft_strchr(buffer, '\n'))
        {
            temp = ft_strjoin(line, get_front(buffer, '\n', 0));
			ft_memmove(buffer, (ft_strchr(buffer, '\n') + 1), ft_strlen((ft_strchr(buffer, '\n') + 1)) +1);
            free(line);
            line = temp;
            break;
        }
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
    }
    return (line);
}


int main ()
{
      /* char * s1 =  get_front("abc\ndfr", '\n', 0);
      char * s2 =  get_front("abc\ndfr", '\n', 1);
    printf("%s\n", s1);
    free(s1);
    printf("%s\n", s2);
     free(s2); */

	int fd = open("test.c", O_RDONLY);
	char *line;

	printf("%d\n", BUFFER_SIZE);
    //printf("%s", get_next_line(fd));

	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	close(fd);
    //printf("%s", ft_strjoin(NULL, "abc"));
}
