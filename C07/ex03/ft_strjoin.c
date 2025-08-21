/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:15:37 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/12 16:15:39 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strs_len(char	**strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

void	ft_clean_str(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strcat(char *dest, char *src, char *sep, int size)
{
	int	i;
	int	j;
	int	if_last;

	j = 0;
	if_last = 1;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (sep[j] && if_last < size)
	{
		dest[i] = sep[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	int		if_last;
	char	*allstr;

	len = 0;
	i = 0;
	if_last = size;
	if (size == 0)
	{
		allstr = (char *) malloc(sizeof(char));
		return (allstr);
	}
	len = ft_strs_len(strs, size);
	allstr = (char *) malloc(sizeof(char) * (len));
	ft_clean_str(allstr, ft_strlen(allstr));
	i = 0;
	while (i < size)
	{
		ft_strcat(allstr, strs[i], sep, if_last);
		if_last--;
		i++;
	}
	return (allstr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"Hello", "world", "!"};
	char	*sep = ",";
	char	*str;

	str = ft_strjoin(3, strs, sep);
	printf("final string: %s\n", str);
	free (str);
	return(0);
}
*/