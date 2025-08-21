/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:01:19 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/11 19:01:21 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *params)
{
	int	i;

	i = 0;
	while (params[i] != '\0')
	{
		write(1, &params[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	q;

	q = 1;
	while (q < argc)
	{
		ft_print_params(argv[q]);
		q++;
	}
	return (0);
}
