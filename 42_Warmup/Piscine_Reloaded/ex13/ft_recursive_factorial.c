/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:17:20 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/07 18:17:22 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	long long	n;

	n = nb;
	if (n < 0 || n > 12)
		return (0);
	if (n < 2)
		return (1);
	else
		return (n * ft_recursive_factorial(n - 1));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_recursive_factorial(5));
	return (0);
}
*/