
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		a = n + '0';
		ft_putchar_fd(a, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		a = (n % 10) + '0';
		ft_putchar_fd(a, fd);
	}
}
