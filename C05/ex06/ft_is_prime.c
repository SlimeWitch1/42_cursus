/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:47:48 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:49 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = nb / 2;
	if (nb < 2)
		return (0);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n;

	n = 0;
	if (ft_is_prime(n) == 0)
		printf("%d não é Primo\n", n);
	else
		printf("%d é Primo\n", n);
	return (0);
}
*/