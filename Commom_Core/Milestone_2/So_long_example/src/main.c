/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:30:52 by turocha-          #+#    #+#             */
/*   Updated: 2025/11/22 21:30:54 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char **argv)
{
	int	row_and_collumn[2];
	int	**matrix;
	int	start[2];

	matrix = NULL;
	if (argc != 2)
	{
		ft_printf("Invalid Arguments\n");
		exit(1);
	}
	if (check_map(argv[1], 0) && set_row_and_collumn(row_and_collumn, argv[1]))
		matrix = create_matrix(row_and_collumn, matrix, argv[1]);
	start[0] = 0; //number of rows on the map; map width.
	start[1] = 0; //number of collumns on the map; map height.
	check_start_errors(row_and_collumn, matrix, argv[1]);
	check_map_path(matrix, argv[1], start, row_and_collumn);
	game_start(matrix, row_and_collumn);
	return (0);
}
