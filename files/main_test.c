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

int	ft_printf(char	*format, ...);

int	main(void)
{
	int	deneme;
	
	deneme = 5;
	printf("%s\n", ft_hextostr_low((unsigned long)&deneme));
	//ft_printf("Ad: %s\nYas: %d\nCinsiyet: %c\n", "Recep", 22, 'E');
	//ft_printf("Deneme Adress: %p", &deneme);
	return (0);
}
