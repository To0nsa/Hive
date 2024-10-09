
#include <libft.h>

void	ft_memprint_dec(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				output[4];
	int					value;
	int					len;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		value = ptr[i];
		len = 0;
		if (value >= 100)
		{
			output[len++] = '0' + (value / 100);
			value %= 100;
		}
		if (value >= 10 || len > 0)
		{
			output[len++] = '0' + (value / 10);
			value %= 10;
		}
		output[len++] = '0' + value;
		output[len++] = ' ';
		write(1, output, len);
		i++;
	}
	write(1, "\n", 1);
}
