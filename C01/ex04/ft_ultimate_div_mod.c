/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:39:16 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/28 15:39:19 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	d;

	d = *a / *b;
	*b = *a % *b;
	*a = d;
}

/*
int	main(void)
{
	int	a = 84;
	int b = 2;
	
	ft_ultimate_div_mod(&a, &b);
	printf("a/b = %d, sobra %d\n", a, b);
	return (0);
}
*/