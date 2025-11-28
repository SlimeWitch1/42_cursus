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

char	*read_not_read(int fd, char *not_read)
{
	char	*buff;
	int		bytes_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(not_read, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(not_read);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		not_read = ft_strjoin_gnl(not_read, buff);
	}
	free(buff);
	return (not_read);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*not_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	not_read = read_not_read(fd, not_read);
	if (!not_read)
		return (NULL);
	line = cur_line(not_read);
	not_read = new_not_read(not_read);
	return (line);
}
