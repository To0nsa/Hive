
#include <libft.h>

void	ft_print_memory_octal(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				output[5];
	int					len;
	int					value;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		len = 0;
		value = ptr[i];
		output[len++] = '0' + (value >> 6);
		output[len++] = '0' + ((value >> 3) & 7);
		output[len++] = '0' + (value & 7);
		output[len++] = ' ';
		write(1, output, len);
		i++;
	}
	write(1, "\n", 1);
}
