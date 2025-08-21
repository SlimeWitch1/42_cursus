/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:46:22 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:46:33 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	size_t	elements = 6;
	char	*str = ft_calloc(elements, 1);
	int		i = elements;

	while (i >= 0)
	{
		if (str[i] == '\0')
			printf("str[%d]: %c%c%c%c\n", i, '\'', '\\', '0', '\'');
		else
			printf("str[%d]: %c", i, str[i]);
		i--;
	}
	free(str);
	return (0);
}
*/