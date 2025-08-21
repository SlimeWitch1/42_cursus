/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:25:24 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/01 16:25:26 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "Hello, ";
	char	s2[] = "world!";
	char	s3[] = "Hello, ";
	char	s4[] = "world!";

	strcat(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", (ft_strcat(s3, s4)));
	return (0);
}
*/