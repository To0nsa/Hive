
#include <libft.h>

void	ft_memprint_bin(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	int					bit;
	char				output[9];

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (ptr[i] & (1 << bit))
				output[7 - bit] = '1';
			else
				output[7 - bit] = '0';
			bit--;
		}
		output[8] = ' ';
		write(1, output, 9);
		i++;
	}
	write(1, "\n", 1);
}