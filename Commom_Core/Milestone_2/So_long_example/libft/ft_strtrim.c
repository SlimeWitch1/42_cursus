/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:57:24 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/13 16:57:25 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	i = 0;
	j = (ft_strlen(s) - 1);
	while (s[i] && ft_strchr(set, s[i]))
		++i;
	while (s[i] && ft_strchr(set, s[j]))
		--j;
	str = ft_substr(s, i, ((j - i) + 1));
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "		this;isa#very-big	string/of^characters	";
	char	*set = "	";

	printf("Str: >%s<\n", str);
	printf("Trimmed: >%s<\n", ft_strtrim(str, set));
	return (0);
}
*/