/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:18:55 by turocha-          #+#    #+#             */
/*   Updated: 2025/08/13 19:41:35 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_all_len(unsigned	long long num, int size)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / size;
	}
	return (len);
}

int	ft_hex(unsigned int num, const char format)
{
	unsigned long long	nb;

	nb = num;
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nb, format);
	return (ft_all_len(num, 16));
}

int	ft_ptr(unsigned long long ptr)
{
	int	print;

	print = 0;
	if (ptr == 0)
		print += write(1, "(nil)", 5);
	else
	{
		print += write(1, "0x", 2);
		ft_puthex(ptr, 'x');
		print += ft_all_len(ptr, 16);
	}
	return (print);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_all_len(n, 10);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_unsigned(unsigned int n)
{
	int		print;
	char	*num;

	print = 0;
	if (n == 0)
		print += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print += ft_iputstr(num);
		free(num);
	}
	return (print);
}
