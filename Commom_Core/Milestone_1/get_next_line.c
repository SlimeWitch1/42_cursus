/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:34:21 by turocha-          #+#    #+#             */
/*   Updated: 2025/09/03 18:34:29 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *file)
{
	char	*buff;
	int		bytes_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(file, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(file);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		file = gnl_strjoin(file, buff);
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*file;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = read_file(fd, file);
	if (!file)
		return (NULL);
	line = current_line(file);
	file = update_file(file);
	return (line);
}
