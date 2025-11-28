/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:04:17 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:04:23 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	analyze_exit(t_map *matrix, int i, int j, int *reach_exit)
{
	if (i < 0 || j < 0 || i >= matrix->row_and_collumn[0] || j >= matrix->row_and_collumn[1]
		|| matrix->matrix[i][j] == 1)
		return ;
	if (matrix->matrix[i][j] == E)
	{
		reach_exit[0] = 1;
		return ;
	}
	matrix->matrix[i][j] = 1;
	analyze_exit(matrix, i - 1, j, reach_exit);
	analyze_exit(matrix, i + 1, j, reach_exit);
	analyze_exit(matrix, i, j - 1, reach_exit);
	analyze_exit(matrix, i, j + 1, reach_exit);
}

void	check_exit(char *map_path, int **matrix, int *index, int *row_and_collumn)
{
	t_map	*map_temp;
	int		reach_exit[1];

	map_temp = NULL;
	map_temp = malloc(sizeof(t_map));
	map_temp->matrix = NULL;
	map_temp->row_and_collumn = NULL;
	reach_exit[0] = 0;
	map_temp->matrix = create_matrix(row_and_collumn, matrix, map_path);
	map_temp->row_and_collumn = row_and_collumn;
	analyze_exit(map_temp, index[0], index[1], reach_exit);
	if (reach_exit[0] != 1)
	{
		ft_printf("No Valid Path\n");
		free_map(map_temp);
		free_matrix(matrix, row_and_collumn[0]);
		exit(1);
	}
	free_map(map_temp);
}

int	set_row_and_collumn(int *row_and_collumn, char *path)
{
	char	*temp_line;
	int		fd;

	fd = open(path, O_RDONLY);
	temp_line = get_next_line(fd);
	row_and_collumn[1] = -1;
	row_and_collumn[0] = 0;
	while (temp_line != NULL)
	{
		if (row_and_collumn[1] == -1)
			row_and_collumn[1] += ft_strlen(temp_line);
		row_and_collumn[0]++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int	*fill_row(int *row, int fd, int limit)
{
	char	*temp_line;
	int		i;

	i = 0;
	temp_line = get_next_line(fd);
	while (i < limit)
	{
		row[i] = temp_line[i] - 48;
		i++;
	}
	free(temp_line);
	return (row);
}

int	**create_matrix(int *row_and_collumn, int **matrix, char *map_path)
{
	int	i;
	int	fd;

	fd = open(map_path, O_RDONLY);
	i = 0;
	matrix = malloc(sizeof(int *) * row_and_collumn[0]);
	while (i < row_and_collumn[0])
	{
		matrix[i] = malloc(sizeof(int) * row_and_collumn[1]);
		matrix[i] = fill_row(matrix[i], fd, row_and_collumn[1]);
		i++;
	}
	close (fd);
	return (matrix);
}
