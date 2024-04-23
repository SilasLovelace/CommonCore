/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:14:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/15 11:14:42 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*free_join(char *scan, char *buffer, int bytes_read)
{
	char	*old;

	if (bytes_read <= 0)
	{
		freeif(&buffer);
		if (bytes_read == -1)
		{
			freeif(&scan);
			return (NULL);
		}
	}
	else
	{
		old = scan;
		scan = ft_strjoin(old, buffer);
		freeif(&old);
		freeif(&buffer);
	}
	if (!scan)
		return (NULL);
	return (scan);
}

//trims the first part of a processed buffer
//probably still faulty baecasue of NULL /EOF handling
char	*trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		freeif(&buffer);
		return (NULL);
	}
	new = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	freeif(&buffer);
	return (new);
}

//extracts everything up to the first newline or terminator
// of the buffer or NULL uf the BUFFER is EMPTY
char	*get_lin(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	while (i >= 0)
	{
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

//gets the file descriptor and a potentially partially filled old buffer
//returns either the buffer unmodified if there is a part up to newline or 
//makes a new read and adds to the buffer until a newline or EOF is found
char	*get_buffer(int fd, char *buffer)
{
	char	*scan;
	size_t	bytes_read;

	while (!ft_strchr(buffer, '\n'))
	{
		scan = calloc(BUFFER_SIZE + 1, 1);
		if (!scan)
			return (freeif(&buffer), NULL);
		bytes_read = read(fd, scan, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			freeif(&scan);
			break ;
		}
		buffer = free_join(buffer, scan, bytes_read);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

//Function that includes other functions
//has a buffer of undefined size and a line of undefined size
//Buffer gets filled up to \n or EOF OR including all newlines
//line gets extracted
//Buffer is adjusted
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_lin(buffer);
	if (line)
		buffer = trim_buffer(buffer);
	else
		freeif(&buffer);
	return (line);
}

/* int main ()
{
	// int fd = open("read_error.txt", O_RDONLY);
	//int fd = open("giant_line.txt", O_RDONLY);
	//int fd = open("giant_line_nl.txt", O_RDONLY);
	int fd = open("1char.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("1. >> %s", line);
	close(fd);
	free(line);
	line = get_next_line(fd);
	printf("2. >> %s", line);
	line = get_next_line(fd);
	printf("2. >> %s", line);

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line); 
	// 	free(line);
	// }
	// 	printf("%s", line); 
	// close(fd);
} */