
#include "game.h"

void	malloc_error(t_game *game, int **matrix, int *row_and_column)
{
	ft_printf("Not enough memory to allocate\n");
	if (matrix)
		free_matrix(matrix, row_and_column[0]);
	free_game(game);
	exit(1);
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
