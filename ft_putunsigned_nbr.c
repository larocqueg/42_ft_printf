/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:50:28 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 14:51:19 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_nbr(unsigned long long n, char *base, int i)
{
	if (n >= 10)
		ft_putnbr_base(n / 10, base, i);
	i += ft_putchar(base[n % 10]);
	return (i);
}
