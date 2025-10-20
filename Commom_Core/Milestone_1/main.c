/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:50:19 by turocha-          #+#    #+#             */
/*   Updated: 2025/09/06 18:50:21 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("[%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
