
#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*## Function: ft_memchr
### Prototype:
 `void	*ft_memchr(const void *s, int c, size_t n)`

### Description:
 The `ft_memchr` function searches the first `n` bytes of the memory area pointed 
 to by `s` for the first occurrence of the byte value `c` (converted to `unsigned char`). 
 The search stops once the byte `c` is found or when `n` bytes have been checked.

### Parameters:
 - `const void *s`: A pointer to the memory area to be searched.
 - `int c`: The byte value to search for. This value is passed as an `int`, but 
 it is converted to an `unsigned char`.
 - `size_t n`: The number of bytes to search.

### Return:
 - Returns a pointer to the first occurrence of the byte `c` in the memory area 
 `s`, or `NULL` if the byte is not found within the first `n` bytes.

### Details:
 - The function treats the memory as a sequence of `unsigned char` values, 
 comparing each byte in the memory area to the byte `c`.
 - If the byte is found, the function returns a pointer to the location of the 
 first occurrence of `c` in the memory area.
 - If `c` is not found in the first `n` bytes, the function returns `NULL`.

### Important notes:
 - The value `c` is converted to `unsigned char` for comparison, ensuring that 
 all possible byte values are handled correctly.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memchr.c -L lib -lft -o test/test_ft_memchr

// ### Examples of usage:
/* #include "libft.h"
#include <stdio.h>
#include <string.h>  // For memchr

// Prototype of ft_memchr
void	*ft_memchr(const void *s, int c, size_t n);

// Prototype of helper functions
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
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
		const void	*sfer;
		int			search_char;
		size_t 		n;
		void		*expected_result;
	}				t_test_case;

	// Define test sfers
	unsigned char sfer1[] = "Hello, World!";
	unsigned char sfer2[] = {0x00, 0x01, 0x02, 0x03, 0x04};
	unsigned char sfer3[] = "Test string with multiple characters";

	// Define test cases
	t_test_case tests[] = {
		{"Test 1: Search for 'W' in \"Hello, World!\"", sfer1, 'W', ft_strlen((char *)sfer1), memchr(sfer1, 'W', ft_strlen((char *)sfer1))},
		{"Test 2: Search for 'z' not in sfer", sfer1, 'z', ft_strlen((char *)sfer1), memchr(sfer1, 'z', ft_strlen((char *)sfer1))},
		{"Test 3: Search for '\\0' in sfer", sfer1, '\0', ft_strlen((char *)sfer1) + 1, memchr(sfer1, '\0', ft_strlen((char *)sfer1) + 1)},
		{"Test 4: Search in zero bytes (n = 0)", sfer1, 'H', 0, memchr(sfer1, 'H', 0)},
		{"Test 5: Search for 0x03 in binary data", sfer2, 0x03, sizeof(sfer2), memchr(sfer2, 0x03, sizeof(sfer2))},
		{"Test 6: Search for 't' in sfer with multiple occurrences", sfer3, 't', ft_strlen((char *)sfer3), memchr(sfer3, 't', ft_strlen((char *)sfer3))},
		{"Test 7: Search for 'T' ", sfer3, 'T', ft_strlen((char *)sfer3), memchr(sfer3, 'T', ft_strlen((char *)sfer3))},
		{"Test 8: Search for negative value -1", sfer1, -1, ft_strlen((char *)sfer1), memchr(sfer1, -1, ft_strlen((char *)sfer1))},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_memchr:\033[0m\n\n");

	while (i < num_tests)
	{
		// Apply ft_memchr
		void *result = ft_memchr(tests[i].sfer, tests[i].search_char, tests[i].n);

		// Print the results
		printf("%s\n", tests[i].description);

		// Print sfer content
		printf("sfer: ");
		fflush(stdout);
		ft_memprint_hex(tests[i].sfer, tests[i].n);

		// Print expected and actual results
		printf("Expected result: ");
		if (tests[i].expected_result)
			printf("Found at position %ld\n", (unsigned char *)tests[i].expected_result - (unsigned char *)tests[i].sfer);
		else
			printf("Not found (NULL)\n");

		printf("ft_memchr result: ");
		if (result)
			printf("Found at position %ld\n", (unsigned char *)result - (unsigned char *)tests[i].sfer);
		else
			printf("Not found (NULL)\n");

		// Compare the results
		if (result == tests[i].expected_result)
			printf("Status \033[32mPASS\033[0m\n");
		else
			printf("Status \033[31mFAIL\033[0m\n");

		printf("---------------------------\n");
		i++;
	}
	return (EXIT_SUCCESS);
} */
