
#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define P 32
# define C 19
# define E 21

typedef struct s_player
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	int		move_count;
}	t_player;

typedef struct s_map
{
	int	**matrix;
	int	*row_and_column;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_map		*map;

	void		*wall_img;
	void		*floor_img;
	void		*exit_open_img;
	void		*exit_closed_img;
	int			can_exit;
	int			tile_width;
	int			tile_height;

	void		*collect_img;
	int			coll_width;
	int			coll_height;
	int			to_collect;

	int			end;
}	t_game;

typedef struct s_map_errors
{
	int	w;
	int	c;
	int	p;
	int	e;
}	t_map_errors;

//free(5)
void	malloc_error(t_game *game, int **matrix, int *row_and_column);
void	free_matrix(int **matrix, int rows);
void	free_map(t_map *map);
void	free_player(t_player *player, t_game *game);
void	free_game(t_game *game);

//map(4)
//void	map_error(int error, int fd, char *temp, char c);
int		check_map(char *path, int i);

//matrix(4)
int		matrix_error(int **matrix, int row, int col);
int		set_row_and_column(int *row_and_column, char *path);
int		**create_matrix(int *row_and_column, int **matrix, char *map_path);

//validation(5)
void	check_matrix(int **matrix, int row, int column, t_map_errors *error);
void	check_extension(int *row_and_column, int **matrix, char *argv1);
void	check_map_path(int **matrix, char *map_path, int *row_and_column);

//game(4)
int		quit(t_game *game);
void	check_to_collect(t_game *game);
int		callbacks(t_game *game);
int		game_start(int **matrix, int *row_and_column);

//init(2)
t_game	*init_game_structs(int **matrix, int *row_and_column);
void	load_images(t_game *game);

//position(3)
int		keyboard_events(int keycode, t_game *game);

//render(3)
void	main_display(t_game *game);

#endif
