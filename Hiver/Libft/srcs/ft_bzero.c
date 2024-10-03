
#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*## Function: ft_bzero
### Prototype:
 `void	ft_bzero(void *s, size_t n)`

### Description:
 The `ft_bzero` function sets the first `n` bytes of the memory area pointed to 
 by `s` to zero. It is commonly used to initialize blocks of memory to all zeroes, 
 ensuring that all data in the specified memory range is cleared.

### Parameters:
 - `void *s`: A pointer to the memory area that will be set to zero.
 - `size_t n`: The number of bytes to set to zero.

### Return:
 - None: This function does not return a value.

### Details:
 - The function casts the memory area pointer `s` to `unsigned char *` to handle 
 the memory byte by byte.
 - It then iterates through the first `n` bytes of the memory area and sets each 
 byte to `0`.
 - This function is typically used to zero out blocks of memory before using them 
 in subsequent operations.

### Important notes:
 - The function does not return any value since it modifies the memory directly.
 - This function is equivalent to `ft_memset(s, 0, n)` but is specialized for 
 setting memory to zero.*/

//### Examples of usage:
static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				hex_digits[17];
	char				output[3];

	ptr = (const unsigned char *)s;
	ft_strcpy(hex_digits, "0123456789abcdef");
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

int main(void)
{
	char test1[10];
	char test2[10];
	char *test3;
	char test4[10];

	// Test Case 1: Typical case (n = 5)
	ft_memset(test1, 'A', 10);
	ft_bzero(test1, 5);
	ft_putstr_fd("Test Case 1: ", 1);
	ft_memprint_hex(test1, 10); // Expected: 00 00 00 00 00 41 41 41 41 41

	// Test Case 2: n = 0 (should not modify the memory)
	ft_memset(test2, 'A', 10);
	ft_bzero(test2, 0);
	ft_putstr_fd("Test Case 2: ", 1);
	ft_memprint_hex(test2, 10); // Expected: No change, 41 41 41 41 41 41 41 41 41 41

	// Test Case 3: Large n value (using dynamic memory)
	test3 = malloc(20);
	if (test3)
	{
		ft_memset(test3, 'B', 20);
		ft_bzero(test3, 20);
		ft_putstr_fd("Test Case 3: ", 1);
		ft_memprint_hex(test3, 20); // Expected: All bytes set to 00
		free(test3);
	}

	// Test Case 4: n = total length (entire array should be zeroed)
	ft_memset(test4, 'C', 10);
	ft_bzero(test4, 10);
	ft_putstr_fd("Test Case 4: ", 1);
	ft_memprint_hex(test4, 10); // Expected: 00 00 00 00 00 00 00 00 00 00

	return (0);
}
 