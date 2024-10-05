
#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*## Function: ft_memcpy
### Prototype:
 `void	*ft_memcpy(void *dest, const void *src, size_t count)`

### Description:
 The `ft_memcpy` function copies `count` bytes from the memory area `src` to the 
 memory area `dest`. The memory areas must not overlap, as the behavior is 
 undefined in such cases. The function returns a pointer to the destination 
 memory `dest`.

### Parameters:
 - `void *dest`: A pointer to the destination memory area where the data will be 
 copied.
 - `const void *src`: A pointer to the source memory area to copy the data from.
 - `size_t count`: The number of bytes to copy from `src` to `dest`.

### Return:
 - Returns a pointer to the destination memory area `dest`.

### Details:
 - The function casts both `src` and `dest` to `unsigned char *` to handle the 
 copy operation byte by byte.
 - It then iterates over the first `count` bytes of the source memory and copies 
 each byte to the destination memory.
 - The function does not handle overlapping memory areas. For overlapping memory, 
 `memmove` should be used instead.

### Important notes:
 - The source and destination memory areas must not overlap, as this can cause 
 undefined behavior.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memcpy.c -L lib -lft -o test/test_ft_memcpy

// ### Examples of usage:
#include <stdio.h>

// Prototype of ft_memcpy 
void	*ft_memcpy(void *dest, const void *src, size_t count);

// Prototype of helper functions
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memset(void *dest, int c, size_t count);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Structure to hold individual test cases
typedef struct s_test_case
{
	const char *src;
	size_t		count;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	char	dest[100];  // Buffer for the destination of ft_memcpy
	t_test_case tests[] = {
		{ "abcdef", 6, "abcdef", "Copy entire buffer" },
		{ "hello", 5, "hello", "Copy smaller buffer" },
		{ "world", 3, "wor", "Copy part of buffer" },
		{ "", 0, "", "Copy empty buffer" },
		{ "test1234", 7, "test123", "Copy exact count" },
		{ "overlap", 4, "over", "Partial copy" }
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	char	*result;

	printf("Testing ft_memcpy:\n");
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%-5s | %-16s | %-7s | %-14s | %-14s | %s | %s\n", "Test", "Source", "Count", "Expected", "Output", "Result", "Description");
	printf("------------------------------------------------------------------------------------------------\n");

	// Iterate through test cases
	while (i < num_tests)
	{
		// Clear the destination buffer for each test
		ft_memset(dest, 0, sizeof(dest));

		// Call ft_memcpy with the current input
		result = ft_memcpy(dest, tests[i].src, tests[i].count);
		printf("%-5zu | %-16s | %-7zu | %-14s | %-14s | ", i + 1, tests[i].src, tests[i].count, tests[i].expected_result, result);

		// Determine PASS or FAIL
		if (ft_strncmp(result, tests[i].expected_result, tests[i].count) == 0)
			printf("PASS   | %s\n", tests[i].description);
		else
			printf("FAIL   | %s\n", tests[i].description);
		i++;
	}
	printf("------------------------------------------------------------------------------------------------\n");
	return (0);
}