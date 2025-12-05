
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
