/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:50:17 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:50:19 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "this;is a#very-big string/of^characters";
	char	c = 'c';
	char	*find = ft_strrchr(str, c);

	printf("Str: %s\n", str);
	printf("To find: %c\n", c);
	if (!(find))
		printf("Not found\n");
	else
		printf("Found: %s\n", find);
	return (0);
}
*/