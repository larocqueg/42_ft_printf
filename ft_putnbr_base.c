/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:29:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 16:46:12 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, char *base, int i)
{
	if (n >= 16)
		i = ft_putnbr_base(n / 16, base, i);
	i += ft_putchar(base[n % 16]);
	return (i);
}
