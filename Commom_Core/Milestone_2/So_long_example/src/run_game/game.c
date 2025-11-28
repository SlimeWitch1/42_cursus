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

#include "../game.h"

int	quit(t_game *game)
{
	if (game && game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_game(game);
	if (game && game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
}

void	check_to_collect(t_game *game)
{
	int	collumn;
	int	row;

	row = 0;
	game->to_collect = 0;
	while (row < game->map->row_and_collumn[0])
	{
		collumn = 0;
		while (collumn < game->map->row_and_collumn[1])
		{
			if (game->map->matrix[row][collumn] == C)
				game->to_collect++;
			collumn++;
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

int	game_start(int **matrix, int *row_and_collumn)
{
	t_game	*game;

	game = init_game_structs(matrix, row_and_collumn);
	game->mlx = mlx_init();
	if (!game->mlx)
		malloc_error(game, matrix, row_and_collumn);
	game->window = mlx_new_window(game->mlx, 32 * row_and_collumn[1],
			32 * row_and_collumn[0], "So long and thanks for all the fish");
	ft_printf("Move with WASD or Arrow Keys.\nCollect all the treasure!\n");
	load_images(game);
	check_to_collect(game);
	mlx_loop_hook(game->mlx, callbacks, game);
	mlx_hook(game->window, 2, 1L << 0, events, game);
	mlx_hook(game->window, 17, 0, quit, game);
	mlx_loop(game->mlx);
	return (0);
}
