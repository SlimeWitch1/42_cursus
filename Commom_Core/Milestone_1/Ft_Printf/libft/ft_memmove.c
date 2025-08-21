/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:48:21 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:48:23 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	s1[] = "string/of^characters";
	char	s2[] = "gaaaaaaaaaaaaa";
	size_t	n = 30;

	printf("SRC: %s\nSize(n): %ld\n", s1, n);
	ft_memmove(s2, s1, n);
	printf("DEST: %s\n", s2);
	return (0);
}
*/