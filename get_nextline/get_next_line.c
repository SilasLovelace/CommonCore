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