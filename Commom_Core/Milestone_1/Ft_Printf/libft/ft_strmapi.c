/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:57:05 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/13 16:57:06 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_test(unsigned int i, char c)
{
	return (c + i);
}

#include <stdio.h>
int	main(void)
{
	char	*str = "123456789";
	char	*new = ft_strmapi(str, &ft_test);

	printf("Str: %s\n", str);
	if (!(new))
		printf("Not found\n");
	else
		printf("New: %s\n", new);
	return (0);
}
*/