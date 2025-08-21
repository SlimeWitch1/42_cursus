/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:34:26 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/07 18:34:28 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	array = (int *) malloc(sizeof(int) * (max - min));
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
/*
#include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = 37;
	int	i = 0;
	int	*array = ft_range(min, max);

	//printf("Range = {");
	while (i < (max - min))
	{
		printf("%s%d", i ? ", " : "", array[i]);
		i++;
	}
	//printf("}\n");
	free(array);
}
*/