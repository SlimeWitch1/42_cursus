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

#include "game.h"

void	start_p1ayer(t_game *game, int i, int j)
{
	game->player->x = j;
	game->player->y = i;
	game->player->move_count = 0;
	game->map->matrix[i][j] = 0;
}

void	render_map(t_game *game, int i, int j)
{
	if (game->map->matrix[i][j] == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img, j * game->tile_w, i * game->tile_h);
	}
	else if (game->map->matrix[i][j] == C)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->collect_img, j * game->coll_w, i * game->coll_h);
	}
}

void	render_exit(t_game *game, int i, int j)
{
	if (game->can_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_open, j * game->tile_w, i * game->tile_h);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_closed, j * game->tile_w, i * game->tile_h);
	}
}

void	main_display(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->row_col[0])
	{
		j = 0;
		while (j < game->map->row_col[1])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->floor_img, j * game->tile_w, i * game->tile_h);
			if (game->map->matrix[i][j] == 1 || game->map->matrix[i][j] == C)
				render_map(game, i, j);
			else if (game->map->matrix[i][j] == E)
				render_exit(game, i, j);
			else if (game->map->matrix[i][j] == P)
				start_p1ayer(game, i, j);
			j++;
		}
		i++;
	}
}

void	load_images(t_game *game)
{
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->player->img = NULL;
	game->exit_closed = NULL;
	game->exit_open = NULL;
	game->collect_img = NULL;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->tile_w, &game->tile_h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->tile_w, &game->tile_h);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&game->coll_w, &game->coll_h);
	game->player->img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player->w, &game->player->h);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &game->tile_w, &game->tile_h);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "textures/exit_open.xpm",
			&game->tile_w, &game->tile_h);
}
