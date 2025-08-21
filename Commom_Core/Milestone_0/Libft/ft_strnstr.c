/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:50:03 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:50:05 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big && !len)
		return (0);
	if (little[0] == '\0' || little == big)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "this;is a#very-big string/of^characters";
	char	*find = "#v";
	char	*found = ft_strnstr(str, find, 40);

	printf("Str: %s\n", str);
	printf("To find: %s\n", find);
	if (!(found))
		printf("Not found\n");
	else
		printf("Found in: %s\n", found);
	return (0);
}
*/