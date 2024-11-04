#include "libftprintf.h"
#include <stdlib.h>

static char	*Convert(unsigned int hex, char *str, int size)
{
	int	digit;
	
	digit = 0;
	size = size - 2;
	while (hex)
	{
		digit = hex % 16;
		if (digit < 10)
			str[size] = digit + '0';
		else
			str[size] = (digit - 10) + 'A';
		size --;
		hex /= 16;
	}
	str[size - 1] = '\0';
	return (str);
}

char	*ft_hextostr_up(unsigned int hex)
{
	int		size;
	char	*str;

	size = ft_get_hex_digit_count(hex) + 1;
	str = (char *)malloc(size);
	if (!str)
		return (0);
	return (Convert(hex, str, size));
}