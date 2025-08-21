/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:36:45 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/31 18:36:47 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (((str[i] >= 'a') && (str[i] <= 'z')) && ((i == 0)
				|| (str[i - 1] < '0') || (str[i - 1] > 'z')
				|| ((str[i - 1] > '9') && (str[i - 1] < 'A'))
				|| ((str[i - 1] > 'Z') && (str[i - 1] < 'a'))))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "Salt, cont tu vas ? 42mots quate-deux; ci~et{un";

	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
*/