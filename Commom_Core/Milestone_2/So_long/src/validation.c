/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:22:15 by turocha-          #+#    #+#             */
/*   Updated: 2025/12/05 15:22:20 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	check_matrix(int **matrix, int row, int column, t_map_errors *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if ((matrix[i][0] != 1 || matrix[i][column - 1] != 1)
				|| (matrix[0][j] != 1 || matrix[row - 1][j] != 1))
				error->w = -1;
			if (matrix[i][j] == P)
				error->p++;
			if (matrix[i][j] == E)
				error->e++;
			if (matrix[i][j] == C)
				error->c++;
			j++;
		}
		i++;
	}
}

static void	analyze_exit(t_map *matrix, int row, int column, int *reach_exit)
{
	if (row < 0 || column < 0 || row >= matrix->row_and_column[0]
		|| column >= matrix->row_and_column[1]
		|| matrix->matrix[row][column] == 1)
		return ;
	if (matrix->matrix[row][column] == E)
	{
		reach_exit[0] = 1;
		return ;
	}
	matrix->matrix[row][column] = 1;
	analyze_exit(matrix, row - 1, column, reach_exit);
	analyze_exit(matrix, row + 1, column, reach_exit);
	analyze_exit(matrix, row, column - 1, reach_exit);
	analyze_exit(matrix, row, column + 1, reach_exit);
}

static void	check_exit(char *map_path, int **matrix,
	int *index, int *row_and_column)
{
	t_map	*map_temp;
	int		reach_exit[1];

	map_temp = NULL;
	map_temp = malloc(sizeof(t_map));
	map_temp->matrix = NULL;
	map_temp->row_and_column = NULL;
	reach_exit[0] = 0;
	map_temp->matrix = create_matrix(row_and_column, matrix, map_path);
	map_temp->row_and_column = row_and_column;
	analyze_exit(map_temp, index[0], index[1], reach_exit);
	if (reach_exit[0] != 1)
	{
		ft_printf("No Valid Path\n");
		free_map(map_temp);
		free_matrix(matrix, row_and_column[0]);
		exit(1);
	}
	free_map(map_temp);
}

void	check_map_path(int **matrix, char *map_path, int *row_and_column)
{
	int	index[2];

	index[0] = 0;
	index[1] = 0;
	while (index[0] < row_and_column[0])
	{
		index[1] = 0;
		while (index[1] < row_and_column[1])
		{
			if (index[0] == row_and_column[0] - 1
				&& index[1] == row_and_column[1] - 1)
				return ;
			if (matrix[index[0]][index[1]] == C
				|| matrix[index[0]][index[1]] == P)
				check_exit(map_path, matrix, index, row_and_column);
			index[1]++;
		}
		index[0]++;
	}
	return ;
}

void	check_extension(int *row_and_column, int **matrix, char *argv1)
{
	if (ft_strncmp(&argv1[ft_strlen(argv1) - 4], ".ber", 4) != 0)
	{
		ft_printf("Invalid extension. Need .ber");
		free_matrix(matrix, row_and_column[0]);
		exit(1);
	}
}
