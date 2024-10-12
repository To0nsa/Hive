
#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*## Function: ft_memcpy
### Prototype:
 `void	*ft_memcpy(void *dest, const void *src, size_t n)`

### Description:
 The `ft_memcpy` function copies `n` bytes from the memory area `src` to the 
 memory area `dest`. The memory areas must not overlap, as the behavior is 
 undefined in such cases. The function returns a pointer to the destination 
 memory `dest`.

### Parameters:
 - `void *dest`: A pointer to the destination memory area where the data will be 
 copied.
 - `const void *src`: A pointer to the source memory area to copy the data from.
 - `size_t n`: The number of bytes to copy from `src` to `dest`.

### Return:
 - Returns a pointer to the destination memory area `dest`.

### Details:
 - The function casts both `src` and `dest` to `unsigned char *` to handle the 
 copy operation byte by byte.
 - It then iterates over the first `n` bytes of the source memory and copies 
 each byte to the destination memory.
 - The function does not handle overlapping memory areas. For overlapping memory, 
 `memmove` should be used instead.

### Important notes:
 - The source and destination memory areas must not overlap, as this can cause 
 undefined behavior.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memcpy.c -L lib -lft -o test/test_ft_memcpy

// ### Examples of usage:
/* #include "libft.h"
#include <stdio.h>
#include <string.h>  // For memcpy

// Prototype of ft_memcpy
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Prototype of helper functions
void	ft_memprint_hex(const void *s, size_t n);

void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	size_t				i;
	const char			*hex_digits = "0123456789abcdef";
	char				output[3];

	output[2] = ' ';
	for (i = 0; i < n; i++)
	{
		output[0] = hex_digits[ptr[i] / 16];
		output[1] = hex_digits[ptr[i] % 16];
		write(1, output, 3);
	}
	write(1, "\n", 1);
}

int main(void)
{
	typedef struct s_test_case
	{
		const char 	*description;
		const void	*src;
		size_t 		n;
		size_t		dest_size;
	}				t_test_case;

	// Define test sources
	unsigned char src1[] = "Hello, World!";
	unsigned char src2[] = {0x00, 0x01, 0x02, 0x03, 0x04};
	unsigned char src3[] = "Another test string";

	// Define test cases
	t_test_case tests[] = {
		{"Test 1: Copy a string to an exact-sized buffer", src1, ft_strlen((char *)src1) + 1, ft_strlen((char *)src1) + 1},
		{"Test 2: Copy binary data", src2, sizeof(src2), sizeof(src2)},
		{"Test 3: Copy zero bytes", src1, 0, ft_strlen((char *)src1) + 1},
		{"Test 4: Copy to a larger buffer", src1, ft_strlen((char *)src1) + 1, 50},
		{"Test 5: Copy a longer string into a smaller buffer (partial copy)", src3, 10, 10},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_memcpy:\033[0m\n\n");

	while (i < num_tests)
	{
		// Allocate destination buffers
		unsigned char *dest_ft;
		unsigned char *dest_std;

		dest_ft = (unsigned char *)malloc(tests[i].dest_size);
		dest_std = (unsigned char *)malloc(tests[i].dest_size);
		if (!dest_ft || !dest_std)
			return (EXIT_FAILURE);

		// Initialize destination buffers with a known pattern
		ft_memset(dest_ft, 0xAA, tests[i].dest_size);
		ft_memset(dest_std, 0xAA, tests[i].dest_size);

		// Apply ft_memcpy
		ft_memcpy(dest_ft, tests[i].src, tests[i].n);

		// Apply standard memcpy
		memcpy(dest_std, tests[i].src, tests[i].n);

		// Compare the results
		int result = ft_memcmp(dest_ft, dest_std, tests[i].dest_size);

		// Print the results
		printf("%s\n", tests[i].description);

		// Print source buffer
		printf("Source: ");
		fflush(stdout);
		ft_memprint_hex(tests[i].src, tests[i].n);

		// Print destination buffers
		printf("Destination after memcpy:     ");
		fflush(stdout);
		ft_memprint_hex(dest_std, tests[i].dest_size);

		printf("Destination after ft_memcpy:  ");
		fflush(stdout);
		ft_memprint_hex(dest_ft, tests[i].dest_size);

		// Compare the results
		if (result == 0)
			printf("Status \033[32mPASS\033[0m\n");
		else
			printf("Status \033[31mFAIL\033[0m\n");
		printf("---------------------------\n");

		// Free allocated memory
		free(dest_ft);
		free(dest_std);
		i++;
	}
	return (EXIT_SUCCESS);
} */