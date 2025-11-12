/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:48:54 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:48:55 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "this;is a#very-big string/of^characters";
	char	c = '#';
	char	*find = ft_strchr(str, c);

	printf("Str: %s\n", str);
	printf("To find: %c\n", c);
	if (!(find))
		printf("Not found\n");
	else
		printf("Found: %s\n", find);
	return (0);
}
*/