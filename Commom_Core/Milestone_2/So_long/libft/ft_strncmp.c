/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:49:53 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:49:54 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && (i < n))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*s1 = "string/of^characters";
	char	*s2 = "strinG/of^characters";
	size_t	n = 5;

	printf("S1: %s\nS2: %s\nCMP:%d\n", s1, s2, ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp("test\200", "test\0", 20));
	printf("%d\n", ft_strncmp("test\200", "test\0", 20));
	return (0);
}
*/