/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:50:35 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:50:37 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "sstTr/Ii*nGé";
	int		i = 0;

	while (str[i] != '\0')
	{
		printf("str[%d]: before %c after %c \n", i, str[i], ft_toupper(str[i]));
		i++;
	}
	return (0);
}
*/