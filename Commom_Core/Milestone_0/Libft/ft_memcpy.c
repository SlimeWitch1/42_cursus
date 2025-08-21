/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:48:01 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:48:03 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "string/of^characters";
	char	s2[] = "";
	size_t	n = 19;
	int		i = 0;

	printf("SRC: %s\nSize(n): %ld\n", s1, n);
	ft_memcpy(s2, s1, n);
	printf("DEST: ");
	while (i < (int)n)
	{
		printf("%c", s2[i]);
		i++;
	}
	printf("\n");
	//The function does not NULL terminate after copy,
	// so I make a loop to print it.
	return (0);
}
*/