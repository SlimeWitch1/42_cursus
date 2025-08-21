/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:58:06 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/01 15:58:08 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// unsigned int i;

// 	i = 0;
// 	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i < n - 1)
// 		i++;
// 	if (n == 0)
// 		return (0);
// 	else
// 		return (s1[i] - s2[i]);
// }
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	cmp;
	unsigned int	n;
	char	s1[] = "";
	char	s2[] = "stringcdsa";

	n = 0;
	cmp = strncmp(s1, s2, n);
	printf("CMP1(s1:s2): %d\n", cmp);
	cmp = ft_strncmp(s1, s2, n);
	printf("CMP2(s1:s2): %d\n", cmp);
	return (0);
}
*/