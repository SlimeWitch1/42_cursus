/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:04:34 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:04:39 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_pos_horiz(int pos_keep, int pos_ch, t_game *game)
{
	if (game->map->matrix[pos_keep][pos_ch] == 1)
		return (0);
	if (game->map->matrix[pos_keep][pos_ch] == C)
	{
		game->map->matrix[pos_keep][pos_ch] = 0;
		check_to_collect(game);
	}
	if (game->map->matrix[pos_keep][pos_ch] == E)
	{
		if (game->can_exit == 1)
			game->end = 1;
		else
		{
			check_to_collect(game);
			return (1);
		}
	}
	ft_printf("Move Count: %d\n", ++game->player->move_count);
	return (1);
}

int	check_pos_vert(int pos_keep, int pos_ch, t_game *game)
{
	if (game->map->matrix[pos_ch][pos_keep] == 1)
		return (0);
	if (game->map->matrix[pos_ch][pos_keep] == C)
	{
		game->map->matrix[pos_ch][pos_keep] = 0;
		check_to_collect(game);
	}
	if (game->map->matrix[pos_ch][pos_keep] == E)
	{
		if (game->can_exit == 1)
			game->end = 1;
		else
		{
			check_to_collect(game);
			return (1);
		}
	}
	ft_printf("Move Count: %d\n", ++game->player->move_count);
	return (1);
}

void	update_pos(int keycode, t_player *player, t_game *game)
{
	if (keycode == W || keycode == UP)
		if (check_pos_vert(player->x, player->y - SPEED, game))
			player->y -= SPEED;
	if (keycode == S || keycode == DOWN)
		if (check_pos_vert(player->x, player->y + SPEED, game))
			player->y += SPEED;
	if (keycode == A || keycode == LEFT)
		if (check_pos_horiz(player->y, player->x - SPEED, game))
			player->x -= SPEED;
	if (keycode == D || keycode == RIGHT)
		if (check_pos_horiz(player->y, player->x + SPEED, game))
			player->x += SPEED;
}

int	events(int key, t_game *game)
{
	if (key == ESC)
		quit(game);
	if ((key == W || key == A || key == S || key == D)
		|| (key == UP || key == LEFT || key == DOWN || key == RIGHT))
		update_pos(key, game->player, game);
	return (0);
}
