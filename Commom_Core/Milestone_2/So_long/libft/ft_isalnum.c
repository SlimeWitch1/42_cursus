/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:46:38 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:46:48 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (8);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "st/ri*ngé";
	int		i = 0;

	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0)
			printf("str[%d]: %c is NOT alphanum\n", i, str[i]);
		else
			printf("str[%d]: %c is alphanum\n", i, str[i]);
		i++;
	}
	return (0);
}
*/