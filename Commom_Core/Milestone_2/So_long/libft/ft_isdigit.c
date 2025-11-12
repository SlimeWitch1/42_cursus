/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:47:21 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:47:23 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "0st/6iNG7*é";
	int		i = 0;

	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			printf("str[%d]: %c is NOT digit\n", i, str[i]);
		else
			printf("str[%d]: %c is digit\n", i, str[i]);
		i++;
	}
	return (0);
}
*/