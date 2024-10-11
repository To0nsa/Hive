
#include <libft.h>

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

/*## Function: ft_memset
### Prototype:
 `void	*ft_memset(void *b, int c, size_t count)`

### Description:
 The `ft_memset` function fills the first `count` bytes of the memory area pointed 
 to by `dest` with the constant byte `c`. It returns a pointer to the memory area 
 `dest`. This function is used to set a block of memory to a specific value.

### Parameters:
 - `void *dest`: A pointer to the memory area to be filled.
 - `int c`: The byte value to be set. This value is passed as an `int`, but it 
 is converted to an unsigned char internally.
 - `size_t count`: The number of bytes to set to the value of `c`.

### Return:
 - Returns a pointer to the memory area `dest`.

### Details:
 - The function first casts the pointer `dest` to a `unsigned char *` because 
 memory is treated byte by byte.
 - It then iterates over the memory area, setting each byte to the value `c` 
 until `count` bytes are processed.
 - The function returns the pointer to the original memory block `dest`.

### Important notes:
 - The value `c` is internally treated as an unsigned char, so any integer 
 passed will be converted to an 8-bit value.*/

 // ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memset.c -L lib -lft -o test/test_ft_memset

// ### Examples of usage:
/* #include "libft.h"
#include <stdio.h>
#include <string.h>  // for memset

// Prototype of ft_memset
void	*ft_memset(void *dest, int c, size_t count);

// Prototype of helper functions
// Prototype of helper functions
int			ft_memcmp(const void *buf1, const void *buf2, size_t count);
void		*ft_memcpy(void *dest, const void *src, size_t count);
static void	ft_memprint_hex(const void *s, size_t n);

static void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				*hex_digits;
	char				output[3];

	ptr = (const unsigned char *)s;
	hex_digits = "0123456789abcdef";
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
	typedef struct	s_test_case
	{
		const char 	*description;
		size_t 		buffer_size;
		int			fill_char;
		size_t 		n;
	}				t_test_case;

	// Unified test cases
	t_test_case tests[] = {
		{"Test 1: Filling 5 bytes of a 10-byte array with 'A'", 10, 'A', 5},
		{"Test 2: Filling 0 bytes (no change expected)", 10, 'B', 0},
		{"Test 3: Filling entire 10-byte array with 'C'", 10, 'C', 10},
		{"Test 4: Filling first 10 bytes of a 20-byte array with 'D'", 20, 'D', 10},
		{"Test 5: Filling more bytes than the array size (edge case)", 10, 'E', 15},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_memset:\033[0m\n\n");

	while (i < num_tests)
	{
		char initial_char = 'A' + i; // Different initial character for each test

		// Allocate and initialize the buffer
		unsigned char *buffer = (unsigned char *)malloc(tests[i].buffer_size);
		if (!buffer)
			return (EXIT_FAILURE);
		// Use standard memset to fill the buffer with the initial character
		ft_memset(buffer, initial_char, tests[i].buffer_size);

		// Create expected buffer
		unsigned char *expected = (unsigned char *)malloc(tests[i].buffer_size);
		if (!expected)
		{
			free(buffer);
			return (EXIT_FAILURE);
		}
		ft_memcpy(expected, buffer, tests[i].buffer_size);

		// Apply standard memset to expected buffer
		memset(expected, tests[i].fill_char, tests[i].n);

		// Apply ft_memset
		ft_memset(buffer, tests[i].fill_char, tests[i].n);

		// Compare the actual buffer with the expected buffer using ft_memcmp
		int result = ft_memcmp(buffer, expected, tests[i].buffer_size);

		// Print the results
		printf("%s\n", tests[i].description);

		printf("Buffer after memset:     ");
		fflush(stdout);
		ft_memprint_hex(expected, tests[i].buffer_size);

		printf("Buffer after ft_memset:  ");
		fflush(stdout);
		ft_memprint_hex(buffer, tests[i].buffer_size);

		// Print test result
		if (result == 0)
			printf("Status \033[32mPASS\033[0m\n");
		else
			printf("Status \033[31mFAIL\033[0m\n");
		printf("---------------------------\n");

		// Free allocated memory
		free(buffer);
		free(expected);
		i++;
	}
	return (EXIT_SUCCESS);
} */