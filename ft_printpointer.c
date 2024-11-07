/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:07:55 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/06 14:33:55 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long long n, char *base);
static int	ft_numlen(unsigned long long n);

int	ft_printpointer(void *ptr)
{
	unsigned long long	address;
	int					len;

	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	address = (unsigned long long)ptr;
	len = ft_numlen(address);
	ft_putnbr_base(address, "0123456789abcdef");
	return (2 + len);
}

static void	ft_putnbr_base(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

static int	ft_numlen(unsigned long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}
/*
#include "./libft/ft_putstr_fd.c"
#include "./libft/ft_putchar_fd.c"
#include "./libft/ft_atoi.c"
#include "./libft/ft_strdup.c"
#include "./libft/ft_strlen.c"
#include <stdio.h>
int	main(void)
{
	char *str = ft_strdup("42!");
	ft_putstr_fd("My ft_printfpointer: ", 1);
	ft_printpointer((void *)str);
	printf("\nOriginal printf: %p\n", (void *)str);
	free(str);
	return (0);
}*/
