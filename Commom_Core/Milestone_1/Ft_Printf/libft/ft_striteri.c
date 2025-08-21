/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:56:40 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/13 16:56:41 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
void	ft_test(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - 32;
    }
    printf("Str[%u]: %c\n", i, *c);
}

int	main(void)
{
	char	str[] = "is a-Str/ing";

	printf("Str: %s\n", str);
	ft_striteri(str, &ft_test);
	printf("New: %s\n", str);
	return (0);
}
*/