/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:56:28 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/15 15:56:30 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	len = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * len);
	i = 0;
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min = -5;
	int	max = 8;
	int	i = 0;
	int	*array;
	int	size = ft_ultimate_range(&array, min, max);

	printf("Array Size: %d\n", size);
	while (i < size)
	{
		printf("Array[%d]: %d\n", i, array[i]);
		i++;
	}
	if (array)
		free(array);
}
*/