/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:19:23 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/03 17:19:24 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while ((nb - 1) > 0)
	{
		i = i * (nb - 1);
		nb--;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n;

	n = 5;
	printf("%d! = %d\n", n, ft_iterative_factorial(n));
	return (0);
}
*/