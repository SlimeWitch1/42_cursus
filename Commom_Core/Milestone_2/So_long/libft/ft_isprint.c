/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:47:29 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:47:31 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "sR3/r6G*ngé";
	int		i = 0;

	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == 0)
			printf("str[%d]: %c is NOT print\n", i, str[i]);
		else
			printf("str[%d]: %c is print\n", i, str[i]);
		i++;
	}
	return (0);
}
*/