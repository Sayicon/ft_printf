#include "../libft/libft.h"

static void recursive_printadress(unsigned long adr, int fd)
{
	if (!adr)
		return ;
	else
	{
		recursive_printadress(adr / 16, fd);
		if ((adr % 16) < 10)
			ft_putchar_fd('0' + (adr % 16) , fd);
		else
			ft_putchar_fd('a' + ((adr % 16) - 10), fd);
	}
}

void	ft_putadress_fd(void *adress, int fd)
{
	ft_putstr_fd("0x", fd);
	recursive_printadress((unsigned long)adress, fd);
}