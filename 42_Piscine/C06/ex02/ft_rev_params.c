/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:01:49 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/11 19:01:50 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *params)
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

	q = argc;
	while (q > 1)
	{
		ft_rev_params(argv[q - 1]);
		q--;
	}
	return (0);
}
