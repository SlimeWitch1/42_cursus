/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:02:16 by turocha-          #+#    #+#             */
/*   Updated: 2025/10/14 14:02:28 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	analyze_matrix(int **matrix, int row, int col, t_map_errors *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((matrix[i][0] != 1 || matrix[i][col - 1] != 1)
				|| (matrix[0][j] != 1 || matrix[row - 1][j] != 1))
				error->w = -1;
			if (matrix[i][j] == P)
				error->p++;
			if (matrix[i][j] == E)
				error->e++;
			if (matrix[i][j] == C)
				error->c++;
			j++;
		}
		i++;
	}
}

int	check_matrix_errors(int **matrix, int row, int col)
{
	t_map_errors	*error;

	error = malloc(sizeof(t_map_errors));
	error->w = 0;
	error->c = 0;
	error->p = 0;
	error->e = 0;
	analyze_matrix(matrix, row, col, error);
	if (error->w == -1 || error->c == 0 || error->e != 1 || error->p != 1)
	{
		if (error->w == -1)
			ft_printf("Invalid Wall: Add Walls (1) on all borders\n");
		else if (error->c == 0)
			ft_printf("Invalid Collectible: Add at least one Collectible (C)\n");
		else if (error->e != 1)
			ft_printf("Invalid Exit : Add exactly 1 Exit (E)\n");
		else if (error->p != 1)
			ft_printf("Invalid Player : Add exactly 1 Player (P)\n");
		free(error);
		return (0);
	}
	free(error);
	return (1);
}

void	map_error(int error, int fd, char *temp, char c)
{
	if (error == 1)
	{
		close (fd);
		ft_printf("Invalid Map");
		exit(1);
	}
	if (error == 2)
	{
		close (fd);
		ft_printf("Invalid Char found : '%c' \n", c);
		if (temp)
			free(temp);
		exit(1);
	}
	if (error == 3)
	{
		close (fd);
		ft_printf("Invalid Map \n");
		if (temp)
			free(temp);
		exit(1);
	}
}

void	check_start_errors(int *row_col, int **matrix, char *argv)
{
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
	{
		ft_printf("Invalid extension. Need .ber");
		free_matrix(matrix, row_col[0]);
		exit(1);
	}
	if (!check_matrix_errors(matrix, row_col[0], row_col[1]))
	{
		free_matrix(matrix, row_col[0]);
		exit(1);
	}
}

void	malloc_error(t_game *game, int **matrix, int *row_col)
{
	ft_printf("Not enough memory to allocate\n");
	if (matrix)
		free_matrix(matrix, row_col[0]);
	free_game(game);
	exit(1);
}
