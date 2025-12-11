
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
