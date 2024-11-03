#include "libftprintf.h"
#include <stdlib.h>

static char	*Convert(unsigned long hex, char *str, int size)
{
	int	digit;
	int	i;
	
	digit = 0;
	str[0] = '0';
	str[1] = 'x';
	str[size - 1] = '\0';
	i = 0;
	while (hex)
	{
		digit = hex % 16;
		if (digit < 10)
			str[size - (++i)] = digit + '0';
		else
			str[size - (++i)] = (digit - 10 + 'a');
		hex /= 16;
	}
	return (str);
}

char	*ft_hextostr_low(unsigned long hex)
{
	int		size;
	char	*str;

	size = ft_get_hex_digit_count(hex);
	str = (char *)malloc(size + 3);
	if (!str)
		return (0);
	return (Convert(hex, str, size));
}