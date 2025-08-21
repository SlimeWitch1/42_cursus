/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:19:13 by turocha-          #+#    #+#             */
/*   Updated: 2025/08/13 19:42:01 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iputchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_iputstr(char *str)
{
	int	print;

	print = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[print])
	{
		write(1, &str[print], 1);
		print++;
	}
	return (print);
}

int	ft_iputnbr(int n)
{
	int		print;
	char	*num;

	print = 0;
	num = ft_itoa(n);
	print = ft_iputstr(num);
	free(num);
	return (print);
}

void	ft_puthex(unsigned long long num, const char format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}
