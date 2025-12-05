/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:04:46 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:04:51 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	start_p1ayer(t_game *game, int row, int column)
{
	game->player->x = column;
	game->player->y = row;
	game->player->move_count = 0;
	game->map->matrix[row][column] = 0;
}

static void	render_map(t_game *game, int row, int column)
{
	if (game->map->matrix[row][column] == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
			column * game->tile_width, row * game->tile_height);
	}
	else if (game->map->matrix[row][column] == C)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->collect_img,
			column * game->coll_width, row * game->coll_height);
	}
	else if (game->map->matrix[row][column] == E)
	{
		if (game->can_exit == 1)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_open_img, column * game->tile_width,
				row * game->tile_height);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_closed_img, column * game->tile_width,
				row * game->tile_height);
		}
	}
}

void	main_display(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->map->row_and_column[0])
	{
		column = 0;
		while (column < game->map->row_and_column[1])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->floor_img, column * game->tile_width,
				row * game->tile_height);
			if (game->map->matrix[row][column] == 1
				|| game->map->matrix[row][column] == C
				|| game->map->matrix[row][column] == E)
				render_map(game, row, column);
			else if (game->map->matrix[row][column] == P)
				start_p1ayer(game, row, column);
			column++;
		}
		row++;
	}
}
