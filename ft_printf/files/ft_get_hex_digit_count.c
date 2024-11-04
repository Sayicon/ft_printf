int ft_get_hex_digit_count(unsigned long adr)
{
	if (!(adr / 16))
		return (1);
	else
		return (1 + ft_get_hex_digit_count(adr / 16));
}
