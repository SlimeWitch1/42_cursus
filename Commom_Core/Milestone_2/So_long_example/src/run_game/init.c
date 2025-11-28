/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:57:43 by turocha-          #+#    #+#             */
/*   Updated: 2025/11/22 21:57:45 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	load_images(t_game *game)
{
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->player->img = NULL;
	game->exit_closed_img = NULL;
	game->exit_open_img = NULL;
	game->collect_img = NULL;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->tile_width, &game->tile_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->tile_width, &game->tile_height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&game->coll_width, &game->coll_height);
	game->player->img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player->width, &game->player->height);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &game->tile_width, &game->tile_height);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx, "textures/exit_open.xpm",
			&game->tile_width, &game->tile_height);
}

t_game	*init_game_structs(int **matrix, int *row_and_collumn)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		malloc_error(NULL, matrix, row_and_collumn);
	game->map = NULL;
	game->player = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		malloc_error(game, matrix, row_and_collumn);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		malloc_error(game, matrix, row_and_collumn);
	game->map->matrix = matrix;
	game->map->row_and_collumn = row_and_collumn;
	game->end = 0;
	game->can_exit = 0;
	return (game);
}
