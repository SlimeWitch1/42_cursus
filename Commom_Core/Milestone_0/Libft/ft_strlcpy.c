/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:49:33 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:49:35 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < (size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src = "String";
	char	dest[4];
	size_t	size = sizeof dest;
	
	printf("Src: %s\nSize(dest): %ld\n", src, size);
	ft_strlcpy(dest, src, size);
	printf("Dest = %s\nSize(src): %ld\n", dest, ft_strlcpy(dest, src, size));
	return (0);
}
*/