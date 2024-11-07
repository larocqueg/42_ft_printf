/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/07 11:05:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	char	*error;
	if (!str)
	{
		error = "invalid/empty string!\n";
		ft_putstr_fd(error, 1);
		return ((int)ft_strlen(error));
	}
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}
