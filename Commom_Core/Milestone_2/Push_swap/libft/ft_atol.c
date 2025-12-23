
#include "libft.h"

long	ft_atol(const char *nptr)
{
	int			i;
	long		sign;
	long		nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}
