int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}
int	ft_putnbr(int c)
{
	int	len;

	len = 0;
	if (c == -2147483648)
		return (ft_putstr("-2147483648"));
	if (c < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-c);
	}
	else if (c >= 10)
	{
		len += ft_putnbr(c / 10);
		len += ft_putchar(c % 10 + '0');
	}	
	else
		len += ft_putchar(c + '0');
	return (len);
}
int	ft_uputnbr(unsigned int n)
{
	int	c;

	c = 0;
	if (n <= 9)
		c += ft_print_char(n + '0');
	else
	{
		c += ft_print_unumber(n / 10);
		c += ft_print_unumber(n % 10);
	}
	return (c);
}
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int ft_base(unsigned long data,int flag,int len)
{
    	int	result;

	result = 0;
	if (data >= len)
		result += hex_base(data / len, flag, len);
	if (flag == 1)
		result += ft_putchar("0123456789abcdef"[data % len]);
	else if (flag == 2)
		result += ft_putchar("0123456789ABCDEF"[data % len]);
	return (result);
}