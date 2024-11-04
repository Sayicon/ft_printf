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

static void	print(char *format, va_list *args)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (*format == 's')
		ft_putstr_fd((char *)va_arg(*args, int *), 1);
	else if (*format == 'c')
		ft_putchar_fd((char)va_arg(*args, int), 1);
	else if (*format == 'u')
		ft_putunsigned(va_arg(*args, unsigned int));
	else if (*format == 'x')
		ft_putstr_fd(ft_hextostr_low(va_arg(*args, unsigned int)), 1);
	else if (*format == 'X')
		ft_putstr_fd(ft_hextostr_up(va_arg(*args, unsigned int)), 1);
	else if (*format == 'p')
		ft_putadress_fd(va_arg(*args, void *), 1);
	else if (*format == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(char	*format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			print(format, &args);
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
