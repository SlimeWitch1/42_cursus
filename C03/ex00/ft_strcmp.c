/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:18:13 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/01 15:18:15 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		diff = 0;
		if (s1[i] != s2[i])
		{
			diff = 1;
			break ;
		}
		i++;
	}
	if (diff == 1)
		return (s1[i] - s2[i]);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	cmp;
	char	s1[] = "strings";
	char	s2[] = "string";

	cmp = strcmp(s1, s2);
	printf("CMP1(s1:s2): %d\n", cmp);
	cmp = ft_strcmp(s1, s2);
	printf("CMP2(s1:s2): %d\n", cmp);
	return (0);
}
*/