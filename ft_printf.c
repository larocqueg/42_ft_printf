/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:25:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/06 14:34:15 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer args has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.

#include "libprintf.h"

static int	ft_type(const char type, void *args);

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	j;

	va_start(args, input);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX", input[i]))
				j += ft_type(input[i], va_arg(args, void *));
			else if (intput [i] == '%')
				j += ft_printfchar('%');
		}
		else
			j += ft_printchar(input[i]);
		i++;
	}
	va_end(agrs);
	return (j);
}

static int	ft_type(const char type, void *args)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += ft_printchar((int)args);
	else if (type == 's')
		i += ft_printstr((char *)args);
	else if (type == 'p')
		i += ft_printpointer((unsigned long)args);
	else if (type == 'd')
		i += ft_printint((int)args);
	else if (type == 'i')
		i += ft_printint((int)args);
	else if (type == 'u')
		i += ft_print((unsigned int)args);
	else if (type == 'x')
		i += ft_printhex((unsigned int)args, 87);
	else if (type == 'X')
		i += ft_printhex((unsigned int)args, 55);
	return (i);
}
