/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:34:49 by turocha-          #+#    #+#             */
/*   Updated: 2025/09/03 18:34:53 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s [i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *file, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!file)
	{
		file = (char *)malloc(1 * sizeof(char));
		file[0] = '\0';
	}
	if (!file || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((gnl_strlen(file) + gnl_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (file)
		while (file[++i] != '\0')
			str[i] = file[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[gnl_strlen(file) + gnl_strlen(buff)] = '\0';
	free(file);
	return (str);
}

char	*current_line(char *file)
{
	int		i;
	char	*str;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
	{
		str[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		str[i] = file[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_file(char *file)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(file) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (file[i] != '\0')
		str[j++] = file[++i];
	str[j] = '\0';
	free(file);
	return (str);
}
