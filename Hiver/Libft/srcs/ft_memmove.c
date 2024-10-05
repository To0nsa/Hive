
#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < s + count)
	{
		while (count--)
			d[count] = s[count];
	}
	else
	{
		while (count--)
			*d++ = *s++;
	}
	return (dest);
}

/*## Function: ft_memmove
### Prototype:
 `void	*ft_memmove(void *dest, const void *src, size_t count)`

### Description:
 The `ft_memmove` function copies `count` bytes from the memory area `src` to the 
 memory area `dest`. It safely handles overlapping memory regions by ensuring 
 that the copy is done in a way that prevents data corruption. The function returns 
 a pointer to the destination memory area `dest`.

### Parameters:
 - `void *dest`: A pointer to the destination memory area where the data will be 
 copied.
 - `const void *src`: A pointer to the source memory area to copy the data from.
 - `size_t count`: The number of bytes to copy from `src` to `dest`.

### Return:
 - Returns a pointer to the destination memory area `dest`.

### Details:
 - The function first checks if `src` and `dest` are overlapping and copies the 
 memory in reverse order if necessary to avoid overwriting data.
 - If `src` and `dest` do not overlap or if `dest` is before `src`, the copy is 
 done normally from the beginning of the memory block.
 - It handles copying byte by byte, converting the pointers to `unsigned char *`.

### Important notes:
 - This function handles overlapping memory areas properly, unlike `memcpy`, 
 which assumes that the memory areas do not overlap.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memmove.c -L lib -lft -o test/test_ft_memmove

// ### Examples of usage:
#include <stdio.h>

// Prototype of ft_memmove 
void	*ft_memmove(void *dest, const void *src, size_t count);

// Prototype of helper functions
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memset(void *dest, int c, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);

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
	char	dest[100];  // Buffer for the destination of ft_memmove
	t_test_case tests[] = {
		{ "abcdef", 6, "abcdef", "Copy entire buffer" },
		{ "hello", 5, "hello", "Copy smaller buffer" },
		{ "world", 3, "wor", "Copy part of buffer" },
		{ "", 0, "", "Copy empty buffer" },
		{ "test123", 7, "test123", "Copy exact count" },
		{ "overlapoverlap", 9, "overlapov", "Overlapping memory regions (forward)" },
		{ "abcdefghij", 10, "abcdefghij", "Copy entire buffer (non-overlapping)" }
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	char	*result;

	// Header
	printf("Testing ft_memmove:\n");
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%-5s | %-16s | %-7s | %-14s | %-14s | %s | %s\n", "Test", "Source", "Count", "Expected", "Output", "Result", "Description");
	printf("------------------------------------------------------------------------------------------------\n");

	// Iterate through test cases
	while (i < num_tests)
	{
		// Clear the destination buffer for each test
		ft_memset(dest, 0, sizeof(dest));

		// If overlapping test, use destination that overlaps with source
		if (i == 5)  // For the overlapping memory test
		{
			ft_memcpy(dest, "overlapoverlap", 15);  // Source and destination overlap
			result = ft_memmove(dest + 2, dest, tests[i].count);
		}
		else
		{
			// Call ft_memmove with the current input
			result = ft_memmove(dest, tests[i].src, tests[i].count);
		}
		printf("%-5zu | %-16s | %-7zu | %-14s | %-14s | ", i + 1, tests[i].src, tests[i].count, tests[i].expected_result, dest);

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