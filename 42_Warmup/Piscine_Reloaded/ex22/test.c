/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:53:52 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/16 20:53:54 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	int	a = 40;
	int	b = -333;

	printf("1: %d\n", ABS(1));
	printf("-1: %d\n", ABS(-1));
	printf("a: %d\n", ABS(a));
	printf("b: %d\n", ABS(b));
	printf("(a + b): %d\n", ABS((a + b)));
	printf("(a - b): %d\n", ABS((a - b)));
	printf("(a * b): %d\n", ABS((a * b)));
	printf("(a / b): %d\n", ABS((a / b)));
	return (0);
}
