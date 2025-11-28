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

static void	start_p1ayer(t_game *game, int row, int collumn)
{
	game->player->x = collumn;
	game->player->y = row;
	game->player->move_count = 0;
	game->map->matrix[row][collumn] = 0;
}

static void	render_map(t_game *game, int row, int collumn)
{
	if (game->map->matrix[row][collumn] == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img, collumn * game->tile_width, row * game->tile_height);
	}
	else if (game->map->matrix[row][collumn] == C)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->collect_img, collumn * game->coll_width, row * game->coll_height);
	}
	else if (game->map->matrix[row][collumn] == E)
	{
		if (game->can_exit == 1)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_open_img, collumn * game->tile_width, row * game->tile_height);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_closed_img, collumn * game->tile_width, row * game->tile_height);
		}
	}
}

void	main_display(t_game *game)
{
	int	row;
	int	collumn;

	row = 0;
	while (row < game->map->row_and_collumn[0])
	{
		collumn = 0;
		while (collumn < game->map->row_and_collumn[1])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->floor_img, collumn * game->tile_width, row * game->tile_height);
			if (game->map->matrix[row][collumn] == 1
				|| game->map->matrix[row][collumn] == C
				|| game->map->matrix[row][collumn] == E)
				render_map(game, row, collumn);
			else if (game->map->matrix[row][collumn] == P)
				start_p1ayer(game, row, collumn);
			collumn++;
		}
		row++;
	}
}
