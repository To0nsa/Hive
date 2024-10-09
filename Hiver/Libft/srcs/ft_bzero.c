
#include "libft.h"

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

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_bzero.c -L lib -lft -o test/test_ft_bzero

//### Examples of usage:
#include "libft.h"
#include <stdio.h>
#include <strings.h>  // for bzero

// Prototype of ft_bzero
void	ft_bzero(void *s, size_t n);

// Prototype of helper functions
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
	typedef struct s_test_case
	{
		const char 	*description;
		size_t 		buffer_size;
		size_t 		n;
	}				t_test_case;

	// Unified test cases
	t_test_case tests[] = {
		{"Test 1: Zeroing first 5 bytes of a 10-byte array", 10, 5},
		{"Test 2: Zeroing 0 bytes (no change expected)", 10, 0},
		{"Test 3: Zeroing entire 10-byte array", 10, 10},
		{"Test 4: Zeroing first 10 bytes of a 20-byte array", 20, 10},
		{"Test 5: Zeroing more bytes than the array size (edge case)", 10, 15},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_bzero:\033[0m\n\n");

	while (i < num_tests)
	{
		char fill_char = 'A' + i; // Different fill character for each test

		// Allocate and initialize the buffer
		unsigned char *buffer = (unsigned char *)malloc(tests[i].buffer_size);
		if (!buffer)
			return (EXIT_FAILURE);
		// Use ft_memset to fill the buffer
		ft_memset(buffer, fill_char, tests[i].buffer_size);

		// Create expected buffer
		unsigned char *expected = (unsigned char *)malloc(tests[i].buffer_size);
		if (!expected)
		{
			free(buffer);
			return (EXIT_FAILURE);
		}
		ft_memcpy(expected, buffer, tests[i].buffer_size);

		// Zero out expected buffer using standard bzero
		bzero(expected, tests[i].n);

		// Apply ft_bzero
		ft_bzero(buffer, tests[i].n);

		// Compare the actual buffer with the expected buffer using ft_memcmp
		int result = ft_memcmp(buffer, expected, tests[i].buffer_size);

		// Print the results
		printf("%s\n", tests[i].description);

		printf("Buffer after bzero: ");
		fflush(stdout);
		ft_memprint_hex(expected, tests[i].buffer_size);
		
		printf("Buffer after ft_bzero: ");
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
}
 