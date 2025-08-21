/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:49:21 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:49:23 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size_dest)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(dest);
	if (!size_dest)
		return (ft_strlen(src));
	if (size > size_dest)
		return (ft_strlen(src) + size_dest);
	while (src[i] != '\0' && ((size + i) < size_dest - 1))
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (size + ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src = "string/of^characters!";
	char	dest[30] = "this;is a#very-big ";
	size_t	size = sizeof(dest);
	size_t	size_end_would;
	size_t	size_end_is;

	printf("Size = %ld\n", size);
	printf("src: %s\ndest: %s\n", src, dest);
	size_end_would = ft_strlcat(dest, src, size);
	printf("Concatenated: %s\n", dest);
	size_end_is = sizeof(dest);
	printf("Size_end_would: %ld\n", size_end_would);
	printf("Size_end_is: %ld\n", size_end_is);
	return (0);
}
*/