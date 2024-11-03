/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:47:15 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/03 22:47:15 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(char	*format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*format == 's')
				ft_putstr_fd((char *)va_arg(args, int *), 1);
			else if (*format == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			else if (*format == 'p')
				ft_putadress_fd(va_arg(args, void *), 1);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
			if (*format)
				format ++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format ++;
		}
	}
	return (0);
}
