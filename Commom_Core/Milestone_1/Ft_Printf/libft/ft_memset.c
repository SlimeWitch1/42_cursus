/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:48:45 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:48:47 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s[] = "Stringstring";

	printf("Original string: %s\n", s);
	ft_memset(s+3, 'a', 5);
	printf("New string: %s\n", s);
	return (0);
}
*/