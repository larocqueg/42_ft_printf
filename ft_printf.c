/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:48 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/09 18:48:54 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...);
static int	ft_putnbr(int nb);
static int	ft_putnbr_neg(long n);
static int	ft_type(const char *type, va_list argument);

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		i;

	i = 0;
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				i += ft_type(str, arguments);
			else
				i += ft_putchar(*str);
		}
		else
		{
			i += ft_putchar(*str);
		}
		str++;
	}
	va_end(arguments);
	return (i);
}

static int	ft_putnbr_neg(long n)
{
	char	str[11];
	int		i;
	int		count;

	i = 0;
	count = 0;
	write(1, "-", 1);
	n = -n;
	if (n == 0)
		return (ft_putchar('0'));
	else
	{
		while (n > 0)
		{
			str[i++] = n % 10 + '0';
			n /= 10;
		}
		while (--i >= 0)
			write(1, &str[i], 1);
		count = i + 1;
	}
	return (count + 1);
}

static int	ft_putnbr(int nb)
{
	char	str[11];
	int		i;
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
		return (ft_putnbr_neg(n));
	else
	{
		i = 0;
		while (n > 0)
		{
			str[i++] = n % 10 + '0';
			n /= 10;
		}
		while (--i >= 0)
			write(1, &str[i], 1);
		count = i;
	}
	return (count);
}

static int	ft_type(const char *type, va_list argument)
{
	int	i;

	i = 0;
	if (*type == 'c')
		i += ft_putchar(va_arg(argument, int));
	else if (*type == 's')
		i += ft_putstr(va_arg(argument, char *));
	else if (*type == 'd' || *type == 'i')
		i += ft_putnbr(va_arg(argument, int));
	else if (*type == 'p')
		i += ft_putpointer(va_arg(argument, char *));
	else if (*type == 'x')
		i += ft_puthex(va_arg(argument, unsigned long));
	return (i);
}
