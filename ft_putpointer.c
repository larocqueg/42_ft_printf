/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:48:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/08 18:02:12 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(void *ptr)
{
	unsigned long long address;

	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	address = (unsigned long long)ft_atoi((char *)ptr);
	ft_putnbr_base(address, "0123456789abcdef");
	return (ft_strlen((char *)ptr) + 2);
}

static void	ft_putnbr_base(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	ft_putchar(base[n % 16]);
}
