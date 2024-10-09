
#include <libft.h>

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)buf1;
	ptr2 = (const unsigned char *)buf2;
	i = 0;
	while (i < count)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*## Function: ft_memcmp
### Prototype:
 `int	ft_memcmp(const void *buf1, const void *buf2, size_t count)`

### Description:
 The `ft_memcmp` function compares the first `count` bytes of the memory areas 
 `buf1` and `buf2`. The comparison is done byte by byte, and it returns an integer 
 indicating whether the first difference between the memory blocks makes `buf1` 
 less than, equal to, or greater than `buf2`.

### Parameters:
 - `const void *buf1`: A pointer to the first memory area.
 - `const void *buf2`: A pointer to the second memory area.
 - `size_t count`: The number of bytes to compare.

### Return:
 - Returns an integer less than 0 if `buf1` is less than `buf2`.
 - Returns 0 if `buf1` is equal to `buf2`.
 - Returns an integer greater than 0 if `buf1` is greater than `buf2`.

### Details:
 - The function treats the memory as a sequence of `unsigned char` values, 
 comparing each byte in `buf1` to the corresponding byte in `buf2`.
 - If a difference is found, the function immediately returns the difference 
 between the two differing bytes.
 - If no difference is found within `count` bytes, the function returns 0.

### Important notes:
 - The function stops comparing as soon as it finds a difference, even if fewer 
 than `count` bytes have been checked.
 - The memory areas `buf1` and `buf2` are treated as sequences of `unsigned char` 
 to ensure correct comparison for all byte values.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memcmp.c -L lib -lft -o test/test_ft_memcmp

// ### Examples of usage:
#include "libft.h"
#include <stdio.h>
#include <string.h>  // For memcmp

// Prototype of ft_memcmp
int	ft_memcmp(const void *buf1, const void *buf2, size_t count);

// Prototype of helper functions
void		*ft_memcpy(void *dest, const void *src, size_t count);
static void	ft_memprint_hex(const void *s, size_t n);

static void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	const char			*hex_digits = "0123456789abcdef";
	char				output[3];

	output[2] = ' ';
	ptr = (const unsigned char *)s;
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
		const void	*buffer1;
		const void	*buffer2;
		size_t 		n;
		int			expected_result;
	}				t_test_case;

	// Define test buffers
	unsigned char buf_a1[] = "Hello, World!";
	unsigned char buf_a2[] = "Hello, World!";
	unsigned char buf_b1[] = "Hello, Wxrld!";
	unsigned char buf_b2[] = "Hello, World!";
	unsigned char buf_c1[] = {0x00, 0x01, 0x02, 0x03, 0x04};
	unsigned char buf_c2[] = {0x00, 0x01, 0x02, 0x03, 0x05};
	unsigned char buf_d1[] = "Short";
	unsigned char buf_d2[] = "Shorter";

	// Define test cases
	t_test_case tests[] = {
		{"Test 1: Compare identical buffers", buf_a1, buf_a2, ft_strlen((char *)buf_a1), memcmp(buf_a1, buf_a2, ft_strlen((char *)buf_a1))},
		{"Test 2: Compare buffers with one different character", buf_b1, buf_b2, ft_strlen((char *)buf_b1), memcmp(buf_b1, buf_b2, ft_strlen((char *)buf_b1))},
		{"Test 3: Compare buffers with binary data", buf_c1, buf_c2, sizeof(buf_c1), memcmp(buf_c1, buf_c2, sizeof(buf_c1))},
		{"Test 4: Compare buffers up to n = 0", buf_a1, buf_b1, 0, memcmp(buf_a1, buf_b1, 0)},
		{"Test 5: Compare buffers with different lengths", buf_d1, buf_d2, ft_strlen((char *)buf_d1), memcmp(buf_d1, buf_d2, ft_strlen((char *)buf_d1))},
		{"Test 6: Compare buffers with negative difference", buf_b2, buf_b1, ft_strlen((char *)buf_b2), memcmp(buf_b2, buf_b1, ft_strlen((char *)buf_b2))},
		{"Test 7: Compare buffers with null bytes", "abc\0def", "abc\0xyz", 7, memcmp("abc\0def", "abc\0xyz", 7)},
		{"Test 8: Compare empty buffers", "", "", 1, memcmp("", "", 1)},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_memcmp:\033[0m\n\n");

	while (i < num_tests)
	{
		int result = ft_memcmp(tests[i].buffer1, tests[i].buffer2, tests[i].n);

		// Print the results
		printf("%s\n", tests[i].description);

		// Print buffer contents
		printf("Buffer 1: ");
		fflush(stdout);
		ft_memprint_hex(tests[i].buffer1, tests[i].n);

		printf("Buffer 2: ");
		fflush(stdout);
		ft_memprint_hex(tests[i].buffer2, tests[i].n);

		// Print expected and actual results
		printf("Expected result: %d\n", tests[i].expected_result);
		printf("ft_memcmp result: %d\n", result);

		// Compare the results
		if ((result == 0 && tests[i].expected_result == 0) ||
			(result < 0 && tests[i].expected_result < 0) ||
			(result > 0 && tests[i].expected_result > 0))
			printf("Status \033[32mPASS\033[0m\n");
		else
			printf("Status \033[31mFAIL\033[0m\n");
		printf("---------------------------\n");
		i++;
	}
	return (EXIT_SUCCESS);
}
