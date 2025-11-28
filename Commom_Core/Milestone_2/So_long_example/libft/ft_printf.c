/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:42:41 by turocha-          #+#    #+#             */
/*   Updated: 2025/08/13 19:41:45 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sort_format(const char str, va_list args)
{
	int	print;

	print = 0;
	if (str == 'c')
		print += ft_iputchar(va_arg(args, int));
	else if (str == 's')
		print += ft_iputstr(va_arg(args, char *));
	else if (str == 'p')
		print += ft_ptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		print += ft_iputnbr(va_arg(args, int));
	else if (str == 'u')
		print += ft_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		print += ft_hex(va_arg(args, unsigned int), str);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print;
	va_list	args;

	print = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX", str[i]))
				print += ft_sort_format(str[i], args);
			else if (str[i] == '%')
				print += ft_iputchar('%');
		}
		else
			print += ft_iputchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
