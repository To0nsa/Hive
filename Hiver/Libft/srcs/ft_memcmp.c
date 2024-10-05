
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
#include <stdio.h>

// Prototype of ft_memcmp:
int	ft_memcmp(const void *buf1, const void *buf2, size_t count);

// Structure to hold individual test cases
typedef struct s_test_case
{
	const char *buf1;
	const char *buf2;
	size_t		count;
	int			expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases for ft_memcmp
	t_test_case tests[] = {
		{ "abcdef", "abcdef", 6, 0, "Identical buffers" },
		{ "abcdef", "abcdez", 5, 0, "Identical for the first 5 bytes" },
		{ "abcdef", "abcdez", 6, -1, "Different buffers, diff at 6th byte" },
		{ "abcdef", "abcdeZ", 6, 1, "Buffers differ in the case of last byte" },
		{ "abc", "abc", 0, 0, "Zero-length comparison" },
		{ "abc", "xyz", 3, -23, "Completely different buffers" },
		{ "", "", 0, 0, "Empty buffers" },
		{ "abc", "aBc", 3, 32, "Case-sensitive comparison" },
		{ "abc", "abc", 2, 0, "Identical first 2 bytes, extra ignored" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	int		result;

	printf("Testing ft_memcmp:\n");
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%-5s | %-10s | %-10s | %-7s | %-10s | %-8s | %s | %s\n", "Test", "Buffer 1", "Buffer 2", "Count", "Expected", "Output", "Result", "Description");
	printf("------------------------------------------------------------------------------------------------\n");

	// Iterate through test cases
	while (i < num_tests)
	{
		// Call ft_memcmp with the current input
		result = ft_memcmp(tests[i].buf1, tests[i].buf2, tests[i].count);
		printf("%-5zu | %-10s | %-10s | %-7zu | %-10d | %-8d | ", i + 1, tests[i].buf1, tests[i].buf2, tests[i].count, tests[i].expected_result, result);

		// Determine PASS or FAIL
		if ((result == 0 && tests[i].expected_result == 0) || 
			(result < 0 && tests[i].expected_result < 0) || 
			(result > 0 && tests[i].expected_result > 0))
			printf("PASS   | %s\n", tests[i].description);
		else
			printf("FAIL   | %s\n", tests[i].description);
		i++;
	}
	printf("------------------------------------------------------------------------------------------------\n");
	return (0);
}