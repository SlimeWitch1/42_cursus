/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:47:04 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:47:06 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1024);
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
		if (ft_isalpha(str[i]) == 0)
			printf("str[%d]: %c is NOT alphabet\n", i, str[i]);
		else
			printf("str[%d]: %c is alphabet\n", i, str[i]);
		i++;
	}
	return (0);
}
*/