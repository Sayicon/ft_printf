#include "libftprintf.h"

void	ft_putunsigned(unsigned int n)
{
	if (!(n <= 9 && n >= 0))
	{
		ft_putunsigned(n / 10);
		ft_putchar_fd((n % 10 + '0'), 1);
	}
	else
		ft_putchar_fd((n + '0'), 1);
}