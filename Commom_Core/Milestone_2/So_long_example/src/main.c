#include "game.h"

int	main(int argc, char **argv)
{
	int	row_and_column[2];
	int	**matrix;

	matrix = NULL;
	if (argc != 2)
	{
		ft_printf("Invalid Arguments\n");
		exit(1);
	}
	if (check_map(argv[1], 0) && set_row_and_column(row_and_column, argv[1]))
		matrix = create_matrix(row_and_column, matrix, argv[1]);
	check_start_errors(row_and_column, matrix, argv[1]);
	check_map_path(matrix, argv[1], row_and_column);
	game_start(matrix, row_and_column);
	return (0);
}
