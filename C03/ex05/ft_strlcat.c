/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:58:26 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/02 14:58:27 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s_dest;
	unsigned int	s_src;

	i = 0;
	s_dest = 0;
	s_src = 0;
	while (dest[s_dest] != '\0')
		s_dest++;
	while (src[s_src] != '\0')
		s_src++;
	if (size <= s_dest)
		return (size + s_src);
	while (src[i] != '\0' && ((s_dest + i) < size - 1))
	{
		dest[s_dest + i] = src[i];
		i++;
	}
	dest[s_dest + i] = '\0';
	return (s_dest + s_src);
}
/*
#include <stdio.h>
int	main(void)
{
	size_t			size;
	unsigned int	size_end;
	char			dest[11] = "1337 42 ";
	char			src[] = "Born to code";
	
	size = sizeof(dest);
	printf("Size = %zu\n", size);
	size_end = ft_strlcat(dest, src, size);
	printf("Size_end = %d\n", size_end);
	printf("dest: %s\n", dest);
	return (0);
}
*/