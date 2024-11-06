/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/06 14:34:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_printstr(char *str)
{
	char	*error;

	error = NULL;
	if (!str)
	{
		ft_putstr(error);
		return ();
	}
	ft_putstr(str, 1);
	return ((int)ft_strlen(str));
}
