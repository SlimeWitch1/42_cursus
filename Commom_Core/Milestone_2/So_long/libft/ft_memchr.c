/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:47:37 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:47:39 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "this;is a#very-big string/of^characters";
	char	c = '#';
	char	*find = ft_memchr(str, c, 40);

	printf("Str: %s\n", str);
	printf("To find: %c\n", c);
	if (!(find))
		printf("Not found\n");
	else
		printf("Found: %s\n", find);
	return (0);
}
*/