/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:47:16 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:17 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if ((nb == 1) || (power == 0))
		return (1);
	else
		return (nb * ft_recursive_power(nb, (power - 1)));
}
/*
#include <stdio.h>
int	main(void)
{
	int	nb;
	int	power;

	nb = 3;
	power = 3;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));
	return (0);
}
*/