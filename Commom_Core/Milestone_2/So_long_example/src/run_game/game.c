#include "../game.h"

void	check_to_collect(t_game *game)
{
	int	column;
	int	row;

	row = 0;
	game->to_collect = 0;
	while (row < game->map->row_and_column[0])
	{
		column = 0;
		while (column < game->map->row_and_column[1])
		{
			if (game->map->matrix[row][column] == C)
				game->to_collect++;
			column++;
		}
		row++;
	}
	if (game->to_collect == 0)
		ft_printf("You collected all the treasure! Find the exit...\n");
	else
		ft_printf("You have %d more treasure to collect.\n", game->to_collect);
}

int	callbacks(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	main_display(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player->img,
		game->player->x * game->player->width, game->player->y * game->player->height);
	mlx_do_sync(game->mlx);
	if (game->to_collect == 0)
		game->can_exit = 1;
	if (game->end == 1)
	{
		ft_printf("YOU WIN!!!\nYou used %d movements...\n",
			game->player->move_count);
		quit(game);
	}
	return (0);
}

int	game_start(int **matrix, int *row_and_column)
{
	t_game	*game;

	game = init_game_structs(matrix, row_and_column);
	game->mlx = mlx_init();
	if (!game->mlx)
		malloc_error(game, matrix, row_and_column);
	game->window = mlx_new_window(game->mlx, 32 * row_and_column[1],
			32 * row_and_column[0], "So long and thanks for all the fish");
	ft_printf("Move with WASD or Arrow Keys.\nCollect all the treasure!\n");
	load_images(game);
	check_to_collect(game);
	mlx_loop_hook(game->mlx, callbacks, game);
	mlx_hook(game->window, 2, 1L << 0, events, game);
	mlx_hook(game->window, 17, 0, quit, game);
	mlx_loop(game->mlx);
	return (0);
}
