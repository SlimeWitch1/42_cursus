/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:34:01 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/28 15:34:03 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int	main(void)
{
	int	a = 84;
	int b = 2;
	int	div;
	int	mod;

	ft_div_mod(a, b, &div, &mod);
	printf("a/b = %d, sobra %d\n", div, mod);
	return (0);
}
*/