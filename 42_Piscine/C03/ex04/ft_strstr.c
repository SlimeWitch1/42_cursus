/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:19:46 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/01 17:19:50 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*find;
	char	s1[] = "Hello, asfffdraef";
	char	s2[] = "lo";
	char	s3[] = "Hello, asfffdraef";
	char	s4[] = "lo";

	find = strstr(s1, s2);
	if (find)
	{
		printf("String found\n");
		printf("First occurrence of string '%s' in '%s' is '%s'\n",
			s2, s1, find);
	}
	else
	{
		printf("String not found\n");
	}
	find = ft_strstr(s1, s2);
	if (find)
	{
		printf("String found\n");
		printf("First occurrence of string '%s' in '%s' is '%s'\n",
			s4, s3, find);
	}
	else
	{
		printf("String not found\n");
	}
	return (0);
}
*/