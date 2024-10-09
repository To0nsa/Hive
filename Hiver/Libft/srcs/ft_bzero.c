
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

// Prototype of ft_bzero
void	ft_bzero(void *s, size_t n);

// Prototype of helper functions
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

static void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				hex_digits[17];
	char				output[3];

	ptr = (const unsigned char *)s;
	ft_strlcpy(hex_digits, "0123456789abcdef", sizeof(hex_digits));
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

typedef struct	s_test_case
{
	const char	*description;
	size_t		n;
}				t_test_case;

int	main(void)
{
	t_test_case	tests[] = {
		{"Test Case 1: Zeroing first 5 bytes of a 10-byte array", 5},
		{"Test Case 2: Zeroing 0 bytes (no change expected)", 0},
		{"Test Case 3: Zeroing entire 10-byte array", 10},
		{"Test Case 4: Zeroing first 10 bytes of a 20-byte dynamic array", 10},
		{"Test Case 5: Zeroing more bytes than the array size (edge case)", 15},
		// Note: Testing NULL pointer is undefined behavior and is omitted
	};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	i = 0;

	printf("\033[4mTesting ft_bzero:\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*buffer_static;
		char	*buffer_dynamic;
		char	*expected_static;
		char	*expected_dynamic;
		size_t	j;
		int		pass = 1; // Assume pass until a discrepancy is found

		printf("%s\n", tests[i].description);

		// Initialize static buffer for Test Cases 1, 2, 3, 5
		buffer_static = malloc(10);
		if (!buffer_static)
		{
			printf("Memory allocation failed for static buffer.\n");
			return (1);
		}
		ft_memset(buffer_static, 'A', 10); // Fill with 'A's

		// Initialize expected buffer for static buffer
		expected_static = malloc(10);
		if (!expected_static)
		{
			printf("Memory allocation failed for expected static buffer.\n");
			free(buffer_static);
			return (1);
		}
		ft_memcpy(expected_static, buffer_static, 10); // Copy initial state

		// Initialize dynamic buffer for Test Case 4
		if (i == 3)
		{
			buffer_dynamic = malloc(20);
			if (!buffer_dynamic)
			{
				printf("Memory allocation failed for dynamic buffer.\n");
				free(buffer_static);
				free(expected_static);
				return (1);
			}
			ft_memset(buffer_dynamic, 'B', 20); // Fill with 'B's

			// Initialize expected dynamic buffer
			expected_dynamic = malloc(20);
			if (!expected_dynamic)
			{
				printf("Memory allocation failed for expected dynamic buffer.\n");
				free(buffer_static);
				free(expected_static);
				free(buffer_dynamic);
				return (1);
			}
			ft_memcpy(expected_dynamic, buffer_dynamic, 20); // Copy initial state
		}
		else
		{
			buffer_dynamic = NULL;
			expected_dynamic = NULL;
		}

		// Apply ft_bzero to zero 'n' bytes
		if (i == 3)
			ft_bzero(buffer_dynamic, tests[i].n);
		else
			ft_bzero(buffer_static, tests[i].n);

		// Modify expected buffers accordingly
		if (i == 3)
		{
			j = 0;
			while (j < tests[i].n && j < 20)
			{
				expected_dynamic[j] = 0;
				j++;
			}
		}
		else
		{
			j = 0;
			while (j < tests[i].n && j < 10)
			{
				expected_static[j] = 0;
				j++;
			}
		}

		// Compare the actual buffer with the expected buffer using memcmp
		if (i == 3)
		{
			if (ft_memcmp(buffer_dynamic, expected_dynamic, 20) != 0)
				pass = 0;
		}
		else
		{
			if (ft_memcmp(buffer_static, expected_static, 10) != 0)
				pass = 0;
		}

		// Print buffers after ft_bzero
		ft_putstr_fd("Result: ", 1);
		if (i == 3)
			ft_memprint_hex(buffer_dynamic, 20);
		else
			ft_memprint_hex(buffer_static, 10);

		// Print PASS or FAIL based on the comparison
		if (pass)
			printf("Status: \033[32mPASS\033[0m\n");
		else
			printf("Status: \033[31mFAIL\033[0m\n");
		printf("---------------------------\n");

		// Free allocated memory
		free(buffer_static);
		free(expected_static);
		if (i == 3)
		{
			free(buffer_dynamic);
			free(expected_dynamic);
		}
		i++;
	}
	return (0);
}
 