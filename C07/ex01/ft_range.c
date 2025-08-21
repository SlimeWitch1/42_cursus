/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:14:24 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/12 16:14:25 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	lenght;

	i = max;
	lenght = 0;
	while (i >= min)
	{
		i--;
		lenght++;
	}
	array = (int *) malloc(sizeof(int) * lenght);
	if (min >= max)
	{
		array = NULL;
		return (0);
	}
	i = 0;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

#include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = -5;
	int	i = 0;
	int	*array = ft_range(min, max);
	int	size = max - min;

	while (i < size)
	{
		printf("Array[%d]: %d\n", i, array[i]);
		i++;
	}
	free(array);
}
