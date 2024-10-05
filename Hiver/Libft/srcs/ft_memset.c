
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
 `void	*ft_memset(void *b, int c, size_t len)`

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
#include <stdio.h>

// Prototype of ft_memset
void	*ft_memset(void *dest, int c, size_t count);

// Prototype of helper functions
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);

// Structure to hold individual test cases
typedef struct 	s_test_case
{
	int			c;
	size_t		count;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	char	dest[100];	// Buffer for the destination of ft_memset
	t_test_case tests[] = {
		{ 'a', 6, "aaaaaa", "Fill buffer with 'a'" },
		{ 'b', 3, "bbb", "Fill part of buffer with 'b'" },
		{ '\0', 5, "\0\0\0\0\0", "Fill with null bytes" },
		{ 'X', 10, "XXXXXXXXXX", "Fill buffer with 'X'" },
		{ 'z', 1, "z", "Fill single byte with 'z'" },
		{ 'A', 0, "", "Fill zero bytes" }
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	char	*result;

	// Header
	printf("Testing ft_memset:\n");
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%-5s | %-9s | %-7s | %-14s | %-14s | %s | %s\n", "Test", "Char", "Count", "Expected", "Output", "Result", "Description");
	printf("------------------------------------------------------------------------------------------------\n");

	// Iterate through test cases
	while (i < num_tests)
	{
		// Clear the destination buffer for each test
		ft_memset(dest, 0, sizeof(dest));

		// Call ft_memset with the current input
		result = ft_memset(dest, tests[i].c, tests[i].count);
		printf("%-5zu | '%c'      | %-7zu | %-14s | %-14s | ", i + 1, tests[i].c, tests[i].count, tests[i].expected_result, dest);

		// Determine PASS or FAIL using ft_memcmp
		if (ft_memcmp(result, tests[i].expected_result, tests[i].count) == 0)
			printf("PASS   | %s\n", tests[i].description);
		else
			printf("FAIL   | %s\n", tests[i].description);
		i++;
	}
	printf("------------------------------------------------------------------------------------------------\n");
	return (0);
}