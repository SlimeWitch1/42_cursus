/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:47:39 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:41 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n;

	n = 25;
	if (ft_sqrt(n) == 0)
		printf("Raíz Quadrada de %d = %s\n", n, "Raíz Irracional");
	else
		printf("Raíz Quadrada de %d = %d\n", n, ft_sqrt(n));
	return (0);
}
*/