#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char* read_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	size_t	i;
	char	delim;
	
	i = 0;
	delim = '\n';

	while (((bytes_read = read(fd, &buffer[i], 1)) > 0) && (buffer[i] != delim) && (i < BUFFER_SIZE - 1))
	{
		i++;
	}
	if (bytes_read < 0 && i == 0)
	{
        	return NULL;
	}
	if (bytes_read == 0)
	{
		printf("END");
        	return NULL;
	}

	return buffer;
}

int main ()
{
	int fd = open("test.c", O_RDONLY);
	int i = 0;
	char *line;
	
	printf("%d\n", BUFFER_SIZE);

	while (i++ < 20)
	{
		line = read_line(fd);
		
		if (*line == 0)
		{
			printf("END");
			break;
		}
		printf("%s", line);
	}
	close(fd);
}
