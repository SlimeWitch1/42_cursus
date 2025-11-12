/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:31:34 by turocha-          #+#    #+#             */
/*   Updated: 2025/08/13 19:41:53 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);

int		ft_iputchar(char c);
int		ft_iputstr(char *str);
int		ft_iputnbr(int n);
void	ft_puthex(unsigned long long num, const char format);

int		ft_all_len(unsigned	long long num, int size);
int		ft_hex(unsigned int num, const char format);
int		ft_ptr(unsigned long long ptr);
char	*ft_uitoa(unsigned int n);
int		ft_unsigned(unsigned int n);

#endif
