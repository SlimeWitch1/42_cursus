/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:00:33 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/31 18:00:36 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "String";
	ft_strupcase(str);
	printf("%s\n", str);
	return (0);
}
*/