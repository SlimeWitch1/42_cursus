
#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s [i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *not_read, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!not_read)
	{
		not_read = (char *)malloc(1 * sizeof(char));
		not_read[0] = '\0';
	}
	if (!not_read || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_gnl(not_read)
					+ ft_strlen_gnl(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (not_read)
		while (not_read[++i] != '\0')
			str[i] = not_read[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(not_read) + ft_strlen_gnl(buff)] = '\0';
	free(not_read);
	return (str);
}

char	*cur_line(char *not_read)
{
	int		i;
	char	*str;

	i = 0;
	if (!not_read[i])
		return (NULL);
	while (not_read[i] != '\0' && not_read[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (not_read[i] != '\0' && not_read[i] != '\n')
	{
		str[i] = not_read[i];
		i++;
	}
	if (not_read[i] == '\n')
	{
		str[i] = not_read[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_not_read(char *not_read)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (not_read[i] != '\0' && not_read[i] != '\n')
		i++;
	if (!not_read[i])
	{
		free(not_read);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(not_read) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (not_read[i] != '\0')
		str[j++] = not_read[++i];
	str[j] = '\0';
	free(not_read);
	return (str);
}
