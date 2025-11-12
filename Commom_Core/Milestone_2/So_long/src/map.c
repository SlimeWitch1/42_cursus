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

#include "game.h"

int	check_map_path(int **matrix, char *map_path, int *start, int *row_col)
{
	if (start[0] == row_col[0] - 1 && start[1] == row_col[1] - 1)
		return (matrix[start[0]][start[1]]);
	if (matrix[start[0]][start[1]] == C || matrix[start[0]][start[1]] == P)
		check_exit(map_path, matrix, start, row_col);
	if (start[1] == row_col[1] - 1)
	{
		start[0]++;
		start[1] = 0;
		return (check_map_path(matrix, map_path, start, row_col));
	}
	start[1]++;
	return (check_map_path(matrix, map_path, start, row_col));
}

int	check_char(int c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'P' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}

int	validate_line(char *line, int len, int *error, char *error_i)
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

int	check_map(char *path, int i)
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
