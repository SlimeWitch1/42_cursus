
#include "../game.h"

static int	check_position(int column, int row, t_game *game)
{
	if (game->map->matrix[row][column] == 1)
		return (0);
	if (game->map->matrix[row][column] == C)
	{
		game->map->matrix[row][column] = 0;
		check_to_collect(game);
	}
	if (game->map->matrix[row][column] == E)
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

static void	update_position(int keycode, t_player *player, t_game *game)
{
	if (keycode == W || keycode == UP)
	{
		if (check_position(player->x, player->y - 1, game))
			player->y -= 1;
	}
	if (keycode == S || keycode == DOWN)
	{
		if (check_position(player->x, player->y + 1, game))
			player->y += 1;
	}
	if (keycode == A || keycode == LEFT)
	{
		if (check_position(player->x - 1, player->y, game))
			player->x -= 1;
	}
	if (keycode == D || keycode == RIGHT)
	{
		if (check_position(player->x + 1, player->y, game))
			player->x += 1;
	}
}

int	keyboard_events(int key, t_game *game)
{
	if (key == ESC)
		quit(game);
	if ((key == W || key == A || key == S || key == D)
		|| (key == UP || key == LEFT || key == DOWN || key == RIGHT))
		update_position(key, game->player, game);
	return (0);
}
