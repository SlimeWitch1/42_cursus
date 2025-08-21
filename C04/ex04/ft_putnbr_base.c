/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:36:30 by turocha-          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:43 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	n;
	int			len;

	if (!ft_check_base(base))
		return ;
	n = nbr;
	len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= len)
		ft_putnbr_base(n / len, base);
	write(1, &base[n % len], 1);
}
/*
int	main(void)
{
	int	n = 0;
	char	*hex = "0123456789abcdef";
	char	*oct = "012345678";
	char	*dec = "0123456789";
	char	*bin = "01";

	write(1, "decimal to decimal: ", 20);
	ft_putnbr_base(n, dec);
	write(1, "\ndecimal to binary: ", 20);
	ft_putnbr_base(n, bin);
	write(1, "\ndecimal to octal: ", 20);
	ft_putnbr_base(n, oct);
	write(1, "\ndecimal to hexadecimal: ", 26);
	ft_putnbr_base(n, hex);
	write(1, "\n", 1);

}
*/