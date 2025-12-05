
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;

	i = 0;
	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	if (!size)
		return (s_size);
	if (d_size > size)
		return (s_size + size);
	while (src[i] != '\0' && ((d_size + i) < size - 1))
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
}
