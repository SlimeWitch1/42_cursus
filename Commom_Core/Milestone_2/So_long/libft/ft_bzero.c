/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:45:08 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:45:34 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		*ptr++ = '\0';
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "Stringstring";
	char	s2[] = "Stringstring";
	int		i = ft_strlen(s1);

	bzero(s1, 5);
	while (i >= 0)
	{
		printf("s1[%d]: %c\n", i, s1[i]);
		i--;
	}
	printf("\n\n");
	i = ft_strlen(s2);
	ft_bzero(s2, 5);
	while (i >= 0)
	{
		printf("s2[%d]: %c\n", i, s2[i]);
		i--;
	}
	return (0);
}
*/