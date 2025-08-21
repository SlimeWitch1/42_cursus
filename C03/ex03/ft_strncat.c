/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:53:11 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/01 16:53:13 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while ((src[j] != '\0') && (j < nb))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "Hello, ";
	char	s2[] = "world!!";
	char	s3[] = "Hello, ";
	char	s4[] = "world!!";

	strncat(s1, s2, 5);
	printf("%s\n", s1);
	printf("%s\n", (ft_strncat(s3, s4, 5)));
	return (0);
}
*/