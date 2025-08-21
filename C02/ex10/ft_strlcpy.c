/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:53:11 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/31 18:53:13 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < (size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

#include <stdio.h>
int	main(void)
{
	char	dest;
	char	src[] = "String";
	unsigned int	size;

	size = sizeof src / sizeof src[0];
	printf("Size: %d\n", (ft_strlcpy(&dest, src, size)));
	printf("Dest = %s\n", &dest);
	return (0);
}
