/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:42:56 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/03 13:42:57 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	long long	nb;
	int			i;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
/*
#include <stdio.h>
int	main(void)
{
	char	number[] = " ---+--+1234ab567"; //-1234
	char	number2[] = "   3"; //3
	char	number3[] = "---  223"; //-223
	char	number4[] = "342 a"; //342
	char	number5[] = "-----123"; //-123

	printf("string %s: %d\n", number, ft_atoi(number));
	printf("string %s: %d\n", number2, ft_atoi(number2));
	printf("string %s: %d\n", number3, ft_atoi(number3));
	printf("string %s: %d\n", number4, ft_atoi(number4));
	printf("string %s: %d\n", number5, ft_atoi(number5));
	return (0);
}
*/