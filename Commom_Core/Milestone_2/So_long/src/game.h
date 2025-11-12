/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:50 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:03:58 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SPEED	1
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
	int		w;
	int		h;
	int		x;
	int		y;
	int		move_count;
}	t_player;

typedef struct s_map
{
	int	**matrix;
	int	*row_col;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_map		*map;

	void		*wall_img;
	void		*floor_img;
	void		*exit_open;
	void		*exit_closed;
	int			can_exit;
	int			tile_w;
	int			tile_h;

	void		*collect_img;
	int			coll_w;
	int			coll_h;
	int			to_collect;

	int			end;
}	t_game;

typedef struct s_map_errors
{
	int	w;
	int	c;
	int	p;
	int	e;
	int	extra;
}	t_map_errors;

//errors
void	analyze_matrix(int **matrix, int row, int col, t_map_errors *error);
int		check_matrix_errors(int **matrix, int row, int col);
void	map_error(int error, int fd, char *temp, char c);
void	check_start_errors(int *row_col, int **matrix, char *argv);
void	malloc_error(t_game *game, int **matrix, int *row_col);

//free
int		quit(t_game *game);
void	free_matrix(int **matrix, int rows);
void	free_map(t_map *map);
void	free_player(t_player *player, t_game *game);
void	free_game(t_game *game);

//game
void	check_to_collect(t_game *game);
int		callbacks(t_game *game);
t_game	*init_game_structs(int **matrix, int *row_col);
int		game_start(int **matrix, int *row_col);
int		main(int argc, char **argv);

//map
int		check_map_path(int **matrix, char *map_path, int *start, int *row_col);
int		check_char(int c);
int		validate_line(char *line, int len, int *error, char *error_i);
int		check_map(char *path, int i);

//matrix
void	analyze_exit(t_map *matrix, int i, int j, int *reach_exit);
void	check_exit(char *map_path, int **matrix, int *index, int *row_col);
int		set_row_col(int *row_col, char *path);
int		*fill_row(int *row, int fd, int limit);
int		**create_matrix(int *row_col, int **matrix, char *map_path);

//position
int		check_pos_horiz(int pos_keep, int pos_ch, t_game *game);
int		check_pos_vert(int pos_keep, int pos_ch, t_game *game);
void	update_pos(int keycode, t_player *player, t_game *game);
int		events(int keycode, t_game *game);

//render
void	start_p1ayer(t_game *game, int i, int j);
void	render_map(t_game *game, int i, int j);
void	render_exit(t_game *game, int i, int j);
void	main_display(t_game *game);
void	load_images(t_game *game);

#endif
