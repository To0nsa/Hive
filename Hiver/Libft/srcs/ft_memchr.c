
#include <libft.h>

void	*ft_memchr(const void *buf, int c, size_t count)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*## Function: ft_memchr
### Prototype:
 `void	*ft_memchr(const void *buf, int c, size_t count)`

### Description:
 The `ft_memchr` function searches the first `count` bytes of the memory area pointed 
 to by `buf` for the first occurrence of the byte value `c` (converted to `unsigned char`). 
 The search stops once the byte `c` is found or when `count` bytes have been checked.

### Parameters:
 - `const void *buf`: A pointer to the memory area to be searched.
 - `int c`: The byte value to search for. This value is passed as an `int`, but 
 it is converted to an `unsigned char`.
 - `size_t count`: The number of bytes to search.

### Return:
 - Returns a pointer to the first occurrence of the byte `c` in the memory area 
 `buf`, or `NULL` if the byte is not found within the first `count` bytes.

### Details:
 - The function treats the memory as a sequence of `unsigned char` values, 
 comparing each byte in the memory area to the byte `c`.
 - If the byte is found, the function returns a pointer to the location of the 
 first occurrence of `c` in the memory area.
 - If `c` is not found in the first `count` bytes, the function returns `NULL`.

### Important notes:
 - The value `c` is converted to `unsigned char` for comparison, ensuring that 
 all possible byte values are handled correctly.*/

// ### Examples of usage:
#include <stdio.h>

// Structure to hold individual test cases
typedef struct	s_test_case
{
	const char 	*buffer;
	int			char_to_find;
	size_t		count;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}

int	main(void)
{
	t_test_case tests[] = {
		{ "hello world", 'o', 11, "o world", "Character in the middle of the string ('o')" },
		{ "hello world", 'h', 11, "hello world", "Character at the start of the string ('h')" },
		{ "hello world", 'd', 11, "d", "Character at the end of the string ('d')" },
		{ "hello world", 'x', 11, NULL, "Character not present in the string ('x')" },
		{ "hello\0world", '\0', 11, "\0world", "Null terminator ('\\0')" },
		{ "", 'a', 0, NULL, "Empty string" },
		{ "abcdef", 'f', 3, NULL, "Character present but outside count range" },
		{ "abcdef", 'a', 1, "abcdef", "Character found within count range" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	void	*result;

	printf("Testing ft_memchr:\n");

	// Iterate through test cases
	while (i < num_tests)
	{
		// Call ft_memchr with the current input
		result = ft_memchr(tests[i].buffer, tests[i].char_to_find, tests[i].count);
		printf("Test %2zu: Buffer = \"%s\", Char = '%c', Count = %zu | Expected = ",
			i + 1,
			tests[i].buffer,
			tests[i].char_to_find,
			tests[i].count);
		if (tests[i].expected_result)
			printf("\"%s\"", tests[i].expected_result);
		else
			printf("NULL");
		printf(" | Result = ");

		if (result)
			printf("\"%s\"", (char *)result);
		else
			printf("NULL");

		// Check the result and determine PASS or FAIL
		if (result == NULL && tests[i].expected_result == NULL)
			printf(" | [PASS] - %s\n", tests[i].description);
		else if (result != NULL && ft_strcmp(result, tests[i].expected_result) == 0)
			printf(" | [PASS] - %s\n", tests[i].description);
		else
			printf(" | [FAIL] - %s\n", tests[i].description);
		i++;
	}
	return (0);
}
