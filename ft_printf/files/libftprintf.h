#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"

int ft_get_hex_digit_count(unsigned long adr);
char	*ft_hextostr_low(unsigned int hex);
char	*ft_hextostr_up(unsigned int hex);
void	ft_putunsigned(unsigned int n);
void	ft_putadress_fd(void *adress, int fd);
int	ft_printf(char	*format, ...);
# endif