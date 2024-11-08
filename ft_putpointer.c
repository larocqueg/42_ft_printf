/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:48:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/08 18:16:02 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <unistd.h>

static void	ft_putnbr_base(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	ft_putchar(base[n % 16]);
}

static int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int	ft_putpointer(void *ptr)
{
	unsigned long long address;

	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	address = (unsigned long long)ptr;
	ft_putnbr_base(address, "0123456789abcdef");
	return (ft_strlen("0x") + 8);
}
