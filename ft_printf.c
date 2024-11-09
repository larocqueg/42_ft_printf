/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:48 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/08 19:10:46 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include "ft_printf.h"
#include "ft_strchr.c"
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putpointer.c"
#include "ft_putunsigned.c"

int	ft_printf(const char *str, ...);
static int	ft_putnbr(int nb);
static int	ft_putnbr_neg(long n);
static int	ft_type(const char *type, va_list argument);

int	main(int ac, char **av)
{
	int	neg = -2147483648;
	int	pos = 2147483647;
	int	zero = 0;
	ft_printf("Here is a char: %c\n", av[1][0]);
	printf("printf(%c)\n", av[1][0]);
	ft_printf("Here is a string: %s\n", av[1]);
	printf("printf(%s)\n", av[1]);
	ft_printf("Here is a negative number: %d\n", neg);
	printf("printf(%d)\n", neg);
	ft_printf("Here is zero number: %d\n", zero);
	ft_printf("Here is a positive number: %d\n", pos);
	printf("printf(%d)\n", pos);
	ft_printf("Here is a negative number: %i\n", neg);
	printf("printf(%i)\n", neg);
	ft_printf("Here is zero number: %i\n", zero);
	ft_printf("Here is a positive number: %i\n", pos);
	printf("printf(%i)\n", pos);
	ft_printf("Here is the pointer of av[1]: %p\n", av[1]);
	printf("printf(%p)\n", av[1]);
	return (0);
}

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
	else if (*type == 'u')
		i += ft_putunsigned(va_arg(argument, unsigned int));
	return (i);
}
