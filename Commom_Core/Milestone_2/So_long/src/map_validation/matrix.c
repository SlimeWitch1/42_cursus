
#include "../game.h"

int	matrix_error(int **matrix, int row, int column)
{
	t_map_errors	*error;

	error = malloc(sizeof(t_map_errors));
	error->w = 0;
	error->c = 0;
	error->p = 0;
	error->e = 0;
	check_matrix(matrix, row, column, error);
	if (error->w == -1 || error->c == 0 || error->e != 1 || error->p != 1)
	{
		if (error->w == -1)
			ft_printf("Invalid Wall: Add Walls (1) on all borders\n");
		else if (error->c == 0)
			ft_printf("Invalid Collectible: Add at least one (C)\n");
		else if (error->e != 1)
			ft_printf("Invalid Exit : Add exactly 1 (E)\n");
		else if (error->p != 1)
			ft_printf("Invalid Player : Add exactly 1 (P)\n");
		free(error);
		return (1);
	}
	free(error);
	return (0);
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
