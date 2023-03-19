#include "ft_printf.h"

int	ft_control(char c, va_list a)
{
	int	chr;

	if (c == 'c')
	{
		chr = va_arg(a, int);
		return (write(1, &chr, 1));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putall(va_arg(a, int), "0123456789", 2, 10));
	else if (c == 'u')
		return (ft_putall(va_arg(a, unsigned), "0123456789", 0, 10));
	else if (c == 's')
		return (ft_putall(0, va_arg(a, char *), 3, 0));
	else if (c == 'p')
		return (ft_putall(va_arg(a, unsigned long), "0123456789abcdef", 1, 16));
	else if (c == 'x')
		return (ft_putall(va_arg(a, unsigned), "0123456789abcdef", 0, 16));
	else if (c == 'X')
		return (ft_putall(va_arg(a, unsigned), "0123456789ABCDEF", 0, 16));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	a;

	va_start(a, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[i++] == ' ')
				return (0);
			len += ft_control(str[i], a);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}