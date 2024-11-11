/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:30:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 17:40:30 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_puthex(unsigned long n);
int		ft_putnbr_base(unsigned long n, char *base, int i, unsigned int baselen);
int		ft_putpointer(void *ptr);
int		ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_putunsigned_nbr(unsigned long long n, char *base, int i);
char	*ft_itoa(int n);

#endif
