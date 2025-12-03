#include "../game.h"

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
