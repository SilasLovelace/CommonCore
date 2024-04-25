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

char	*free_join(char *scan, char *buffer, int bytes_read)
{
	char	*old;

	if (bytes_read == 0)
		free(buffer);
    else if (bytes_read == -1)
    {
        free(buffer);
        free(scan);
        return (NULL);
    }
	else
	{
		old = scan;
		scan = ft_strjoin(old, buffer);
		free(old);
		free(buffer);		
	}
	if (!scan)
	{
		return (NULL);
	}	
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
	if(!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new)
		return NULL;
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	free(buffer);
	return (new);
}

//extracts everything up to the first newline or terminator of the buffer or NULL uf the BUFFER is EMPTY
char	*get_line(char *buffer)
{
	char	*line;
	int	i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while(*buffer)
	{
		i++;
		if (buffer[i] == '\n')
			break ;
	}
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	while (--i >= 0)
	{
		line[i] = buffer[i];
		//i--;
	}
	return (line);
}

//gets the file descriptor and a potentially partially filled old buffer
//returns either the buffer unmodified if there is a part up to newline or makes a new read and adds to the buffer until a newline or EOF is found
char *get_buffer(int fd, char *buffer)
{
    char *scan;
    size_t bytes_read;

    while (!ft_strchr(buffer, '\n'))
    {
        scan = calloc(BUFFER_SIZE + 1, 1);
        if (!scan)
            return (NULL);
        bytes_read = read(fd, scan, BUFFER_SIZE);
		if (bytes_read == 0)
		{
            free(scan);
            break;
        }
        buffer = free_join(buffer, scan, bytes_read);
		if (!buffer)
			return (NULL);
    }
    return buffer;
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

	//if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	//printf("\n--%s--\n", buffer);
	buffer = trim_buffer(buffer);
	return (line);
}


int main ()
{
	int fd = open("test.c", O_RDONLY);
	char *line;

	/* printf("%d\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line); */
	printf("%d\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
/* 	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd)); */
	close(fd);
}


/*
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

// join and free
char	*join_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
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
 */

/* //expects a null terminated buffer; Checks for deliminator returns malloced front (includung deliminator) or back both null terminated;
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
} */