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
#include <fcntl.h>

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
	if (bytes_read < 0)
	{
        //perror("Error in reading from file descriptor\n");
        return NULL;
	}
	buffer[i] = '\0';  // Null-terminate the string
	return buffer;
}
