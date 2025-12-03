#include "game.h"

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

void	free_matrix(int **matrix, int rows)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->matrix)
			free_matrix(map->matrix, map->row_and_column[0]);
		free(map);
	}
}

void	free_player(t_player *player, t_game *game)
{
	if (player)
	{
		if (game->mlx && player->img)
			mlx_destroy_image(game->mlx, player->img);
		free(player);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		free_player(game->player, game);
	if (game->mlx && game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->mlx && game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->mlx && game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->mlx && game->exit_open_img)
		mlx_destroy_image(game->mlx, game->exit_open_img);
	if (game->mlx && game->exit_closed_img)
		mlx_destroy_image(game->mlx, game->exit_closed_img);
	if (game->mlx && game->map)
		free_map(game->map);
}

#include "game.h"

void	free_matrix(int **matrix, int rows)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->matrix)
			free_matrix(map->matrix, map->row_and_collumn[0]);
		free(map);
	}
}

void	free_player(t_player *player, t_game *game)
{
	if (player)
	{
		if (game->mlx && player->img)
			mlx_destroy_image(game->mlx, player->img);
		free(player);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		free_player(game->player, game);
	if (game->mlx && game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->mlx && game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->mlx && game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->mlx && game->exit_open_img)
		mlx_destroy_image(game->mlx, game->exit_open_img);
	if (game->mlx && game->exit_closed_img)
		mlx_destroy_image(game->mlx, game->exit_closed_img);
	if (game->mlx && game->map)
		free_map(game->map);
}
