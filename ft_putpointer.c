/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:48:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 17:39:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	int					counter;

	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	address = (unsigned long)ptr;
	counter = 0;
	counter = ft_putnbr_base(address, "0123456789abcdef", counter, 16);
	return (counter + 2);
}
