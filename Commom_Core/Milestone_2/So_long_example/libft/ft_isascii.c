/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:47:12 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:47:14 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "st/r6iNG*ngé";
	int		i = 0;

	while (str[i] != '\0')
	{
		if (ft_isascii(str[i]) == 0)
			printf("str[%d]: %c is NOT alscii\n", i, str[i]);
		else
			printf("str[%d]: %c is alscii\n", i, str[i]);
		i++;
	}
	return (0);
}
*/