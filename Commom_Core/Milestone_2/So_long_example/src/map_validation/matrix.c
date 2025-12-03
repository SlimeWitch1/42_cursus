#include "../game.h"

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

void	check_exit(char *map_path, int **matrix, int *index, int *row_and_column)
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

int	set_row_and_column(int *row_and_column, char *path)
{
	char	*temp_line;
	int		fd;

	fd = open(path, O_RDONLY);
	temp_line = get_next_line(fd);
	row_and_column[1] = -1;
	row_and_column[0] = 0;
	while (temp_line != NULL)
	{
		if (row_and_column[1] == -1)
			row_and_column[1] += ft_strlen(temp_line);
		row_and_column[0]++;
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

int	**create_matrix(int *row_and_column, int **matrix, char *map_path)
{
	int	i;
	int	fd;

	fd = open(map_path, O_RDONLY);
	i = 0;
	matrix = malloc(sizeof(int *) * row_and_column[0]);
	while (i < row_and_column[0])
	{
		matrix[i] = malloc(sizeof(int) * row_and_column[1]);
		matrix[i] = fill_row(matrix[i], fd, row_and_column[1]);
		i++;
	}
	close (fd);
	return (matrix);
}
