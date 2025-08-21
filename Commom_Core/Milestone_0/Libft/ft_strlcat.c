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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;

	i = 0;
	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	if (!size)
		return (s_size);
	if (d_size > size)
		return (s_size + size);
	while (src[i] != '\0' && ((d_size + i) < size - 1))
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
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