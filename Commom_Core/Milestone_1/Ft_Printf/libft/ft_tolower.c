/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:50:28 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/12 21:50:29 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "STr/Ii*nGé";
	int		i = 0;

	while (str[i] != '\0')
	{
		printf("str[%d]: before %c after %c \n", i, str[i], ft_tolower(str[i]));
		i++;
	}
	return (0);
}
*/