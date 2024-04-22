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

//expects a null terminated buffer; Checks for deliminator returns malloced front (includung deliminator) or back both null terminated;
char *get_front(char *buffer, char delim, char front_back)
{
	char	*res;
	char	*delim_pos;

	if (!buffer || !*buffer) return NULL;
	delim_pos = ft_strchr(buffer, delim);
	if (!delim_pos) return ft_strdup(buffer);
	if (front_back == 0)
	{
		res = calloc((delim_pos - buffer + 2), sizeof(char));
		if(!res) return NULL;
		res = ft_memcpy(res, buffer ,delim_pos - buffer + 1);
		return (res);
	}
	delim_pos++;
	res = calloc(ft_strlen(delim_pos) + 1, sizeof(char));
	if(!res) return NULL;
	res = ft_memcpy(res, delim_pos ,ft_strlen(delim_pos));
		return (res);
}



char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}


int main ()
{
	int fd = open("test.c", O_RDONLY);
	int i = 0, x = 0;
	char *line;

	printf("%d\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	close(fd);
}
