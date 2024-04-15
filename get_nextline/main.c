#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

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

	return buffer;
}

int main ()
{
	int fd = open("test.c", O_RDONLY);
	int i = 0;
	char *line;

	while (i++ < 20)
	{
		line = read_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
	}
}
