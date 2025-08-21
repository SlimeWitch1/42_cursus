/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:45:00 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:46:02 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long		sign;
	long long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(sign * nb));
}
/*
#include <stdio.h>
int	main(void)
{
	char	number[] = " +1234ab567"; //-1234
	char	number2[] = "   3"; //3
	char	number3[] = "---  223"; //-223
	char	number4[] = "342 a"; //342
	char	number5[] = "					-123"; //-123

	printf("string %s: %d\n", number, ft_atoi(number));
	printf("string %s: %d\n", number2, ft_atoi(number2));
	printf("string %s: %d\n", number3, ft_atoi(number3));
	printf("string %s: %d\n", number4, ft_atoi(number4));
	printf("string %s: %d\n", number5, ft_atoi(number5));
	return (0);
}
*/