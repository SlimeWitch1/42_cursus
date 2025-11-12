/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:06 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:03:29 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_to_collect(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	game->to_collect = 0;
	while (i < game->map->row_col[0])
	{
		j = 0;
		while (j < game->map->row_col[1])
		{
			if (game->map->matrix[i][j] == C)
				game->to_collect++;
			j++;
		}
		i++;
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
		game->player->x * game->player->w, game->player->y * game->player->h);
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

t_game	*init_game_structs(int **matrix, int *row_col)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		malloc_error(NULL, matrix, row_col);
	game->map = NULL;
	game->player = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		malloc_error(game, matrix, row_col);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		malloc_error(game, matrix, row_col);
	game->map->matrix = matrix;
	game->map->row_col = row_col;
	game->end = 0;
	game->can_exit = 0;
	return (game);
}

int	game_start(int **matrix, int *row_col)
{
	t_game	*game;

	game = init_game_structs(matrix, row_col);
	game->mlx = mlx_init();
	if (!game->mlx)
		malloc_error(game, matrix, row_col);
	game->window = mlx_new_window(game->mlx, 32 * row_col[1],
			32 * row_col[0], "So long and thanks for all the fish");
	ft_printf("Move with WASD or Arrow Keys.\nCollect all the treasure!\n");
	load_images(game);
	check_to_collect(game);
	mlx_loop_hook(game->mlx, callbacks, game);
	mlx_hook(game->window, 2, 1L << 0, events, game);
	mlx_hook(game->window, 17, 0, quit, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int	row_col[2];
	int	**matrix;
	int	start[2];

	matrix = NULL;
	if (argc != 2)
	{
		ft_printf("Invalid Arguments\n");
		exit(1);
	}
	if (check_map(argv[1], 0) && set_row_col(row_col, argv[1]))
		matrix = create_matrix(row_col, matrix, argv[1]);
	start[0] = 0;
	start[1] = 0;
	check_start_errors(row_col, matrix, argv[1]);
	check_map_path(matrix, argv[1], start, row_col);
	game_start(matrix, row_col);
	return (0);
}
