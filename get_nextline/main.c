#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char* get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	size_t	i;
	char	delim;
	
	i = 0;
	delim = '\n';

	if (((bytes_read = read(fd, &buffer[i], 1)) > 0) && (buffer[i] == delim))
		return ("\n");
	while (((bytes_read = read(fd, &buffer[i], 1)) > 0) && (buffer[i] != delim) && (i < BUFFER_SIZE - 1))
		i++;
	if (bytes_read <= 0 && i == 0)
        	return NULL;
	return buffer;
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