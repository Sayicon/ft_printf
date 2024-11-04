/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:47:28 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/03 22:47:28 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libftprintf.h"
#include "stdio.h"

#define HEX 0x1234abcd

int	ft_printf(char	*format, ...);

int	main(void)
{

	printf("%x\n", HEX);
	ft_printf("%x\n", HEX);
	ft_printf("%X\n-----\n", HEX);
	printf("%p\n",&ft_printf);
	ft_printf("%p\n",&ft_printf);
	ft_printf("%u\n", 4294967295);
	//ft_printf("Ad: %s\nYas: %d\nCinsiyet: %c\n", "Recep", 22, 'E');
	//ft_printf("Deneme Adress: %p", &deneme);
	return (0);
}
