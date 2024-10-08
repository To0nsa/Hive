
#include <libft.h>

static void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				hex_digits[17];
	char				output[3];

	ptr = (const unsigned char *)s;
	*hex_digits = "0123456789abcdef";
	output[2] = ' ';
	i = 0;
	while (i < n)
	{
		output[0] = hex_digits[ptr[i] / 16];
		output[1] = hex_digits[ptr[i] % 16];
		write(1, output, 3);
		i++;
	}
	write(1, "\n", 1);
}