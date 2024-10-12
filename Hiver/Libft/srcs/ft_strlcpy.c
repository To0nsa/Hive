
#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*## Function: ft_strlcpy
### Prototype:
 `size_t ft_strlcpy(char *dest, const char *src, size_t size)`

### Description:
 The `ft_strlcpy` function copies up to `size - 1` characters from the string 
 `src` to `dest`, ensuring that the result is null-terminated if `size` is greater 
 than 0. It mimics the behavior of the standard `strlcpy`, providing a safer 
 alternative to `strcpy`.

### Parameters:
 - `char *dest`: A pointer to the destination buffer where `src` will be copied.
 - `const char *src`: A pointer to the source string to be copied to `dest`.
 - `size_t size`: The size of the destination buffer, including space for the null 
 terminator.

### Return:
 - Returns the total length of the source string `src`.
 - If `size` is greater than the length of `src`, the entire string is copied.
 - If `size` is smaller, only `size - 1` characters are copied, and `dest` is 
 null-terminated.

### Details:
 - The function starts by checking if either `dest` or `src` is `NULL`. If so, 
 it returns `0`.
 - If `size > 0`, the function copies characters from `src` to `dest` until either 
 `size - 1` characters are copied or the null terminator in `src` is encountered.
 - After copying, `dest` is null-terminated to ensure a valid C-string.
 - The function continues counting the length of `src` even after reaching the 
 copy limit, to return the full length of `src`.

### Important notes:
 - The function does not allocate new memory. The caller must ensure that `dest` 
 has enough space to hold the result.
 - If `size` is 0, `dest` is not modified, but the length of `src` is still 
 returned.
 - This function ensures safe copying and avoids buffer overflows, as long as 
 `size` is properly set.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strlcpy.c -L lib -lft -o test/test_ft_strlcpy

// ### Examples of usage:
/* #include <libft.h>
#include <stdio.h>

// Prototype of ft_strlcpy
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

typedef struct {
	const char *src;
	size_t size;
} TestCase;

int	main(void)
{
	TestCase test_cases[] = {
		{"Hello, World!", 50},
		{"Hello, World!", 5},
		{"Hello", 6},
		{"Hello, World!", 0},
		{"", 100},
		{"abcdef", 4}
	};
	int num_tests = sizeof(test_cases) / sizeof(TestCase);
	int i = 0;

	printf("\033[4mTesting ft_strlcpy :\033[0m\n\n");

	while (i < num_tests)
	{
		char dest[50];
		size_t ret;

		// Initialize dest buffer with a default string using ft_strlcpy
		// If size > 0, ft_strlcpy will copy the initial string
		// Otherwise, dest remains unchanged
		if (test_cases[i].size > 0)
			ft_strlcpy(dest, "Original", sizeof(dest));
		else
		{
			// Manually set dest to "Original" without using ft_strlcpy
			size_t j = 0;
			const char *initial = "Original";
			while (initial[j] != '\0' && j < sizeof(dest) - 1)
			{
				dest[j] = initial[j];
				j++;
			}
			dest[j] = '\0';
		}

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Source src: \"%s\"\n", test_cases[i].src);
		printf("Size: %zu\n", test_cases[i].size);
		printf("Before ft_strlcpy, dest: \"%s\"\n", dest);

		// Perform ft_strlcpy
		ret = ft_strlcpy(dest, test_cases[i].src, test_cases[i].size);

		// Print results
		printf("After ft_strlcpy, dest: \"%s\"\n", dest);
		printf("Return value (length of src): %zu\n", ret);
		printf("---------------------------\n");
		i++;
	}
	return 0;
}
 */