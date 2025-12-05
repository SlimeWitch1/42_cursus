/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:04:07 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:04:11 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	map_error(int error, int fd, char *temp, char c)
{
	if (error == 1)
	{
		close (fd);
		ft_printf("Invalid Map or File not Found");
		exit(1);
	}
	if (error == 2)
	{
		close (fd);
		ft_printf("Invalid Char found : '%c' \n", c);
		if (temp)
			free(temp);
		exit(1);
	}
	if (error == 3)
	{
		close (fd);
		ft_printf("Invalid Map 3 \n");
		if (temp)
			free(temp);
		exit(1);
	}
}

static int	check_char(int c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'P' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}

static int	validate_line(char *line, int len, int *error, char *error_i)
{
	int	i;

	i = 0;
	while (check_char(line[i]) && i != len)
		i++;
	if (line[i] != '\0')
	{
		*error = 2;
		*error_i = line[i];
		return (0);
	}
	return (1);
}

int	check_map(char *path)
{
	int		len;
	int		fd;
	char	*temp;
	int		error;
	char	error_i;

	error = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		map_error(1, 0, NULL, 0);
	temp = get_next_line(fd);
	if (!temp)
		map_error(3, fd, NULL, 0);
	len = ft_strlen(temp);
	while (temp)
	{
		if (error == 0)
			validate_line(temp, len, &error, &error_i);
		free(temp);
		temp = get_next_line(fd);
	}
	if (error != 0)
		map_error(2, fd, temp, error_i);
	close(fd);
	return (1);
}
