#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_control(char c, va_list a);
int	ft_printf(const char *str, ...);
int	ft_putchar(char s);
int	ft_putnbr(int c);
int	ft_uputnbr(unsigned int n);
int	ft_putstr(char *str);
int ft_base(unsigned long data,int flag,int len);
#endif