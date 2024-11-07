/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:22:26 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/07 11:30:45 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
#include "/home/gde-la-r/Documents/42_Common-Core/42_Libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printpointer(void *ptr);

#endif
