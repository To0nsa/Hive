
#include <libft.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*## Function: `ft_strchr`
### Prototype:
 `char	*ft_strchr(const char *str, int c)`

### Description:
 The `ft_strchr` function searches for the first occurrence of the character `c`
 in the string pointed to by `str`. It scans through the string, including the 
 null terminator `\0`.

### Parameters:
 - `const char *str`: A pointer to the string in which the search will be performed.
 - `int c`: The character to search for, passed as an `int` but internally cast to `char`.

### Return:
 - Returns a pointer to the first occurrence of the character `c` in the string `str`.
 - If `c` is not found, the function returns `NULL`.
 - If `c` is the null terminator (`\0`), the function returns a pointer to
 the null terminator in `str`.

### Details:
 - The function begins by iterating through the string `str` one character at a time.
 - For each character, it checks if the current character matches the given `c` 
 (converted to `char`).
 - If a match is found, the function immediately returns a pointer to that character
 within the string.
 - If no match is found by the end of the string and `c` is the null terminator, 
 it returns a pointer to the null terminator at the end of the string.
 - If the character `c` is not found in the string (and it's not the null terminator),
 the function returns `NULL`.

### Important notes:
 - The search includes the null-terminator character `\0`, meaning if `c` is `\0`, 
 the function will return a pointer to the null terminator in `str`.
 - If `c` is not found in the string, the returned `NULL` should be handled to avoid
 dereferencing null pointers.
 - Since `c` is passed as an `int`, it is cast to `char` internally for comparison 
 with the characters in the string.
*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strchr.c -L lib -lft -o test/test_ft_strchr

// ### Examples of usage:
/* #include <libft.h>
#include <stdio.h>

// Prototype of ft_strchr (Assumed to be declared in libft.h)
char	*ft_strchr(const char *str, int c);

void	print_strchr_result(int test_number, const char *str, int c, char *result)
{
	if (c == '\0') {
		printf("\033[4mTest %d:\033[0m Searching for null terminator '\\0' in \"%s\"\n", test_number, str);
		if (result != NULL)
			printf("        Found '\\0' at the end of the string.\n");
		else
			printf("        Null terminator '\\0' not found.\n");
	} else {
		printf("\033[4mTest %d:\033[0m Searching for '%c' in \"%s\"\n", test_number, c, str);
		if (result != NULL)
			printf("        Found '%c' at: %s\n", c, result);
		else
			printf("        Character '%c' not found.\n", c);
	}
	printf("\n");
}

int	main(void)
{
	char *result;

	printf("\n\033[4mTesting ft_strchr :\033[0m\n\n");
	
	// Test 1: Search for a character in the middle of the string
	result = ft_strchr("Hello, world!", 'o');
	print_strchr_result(1, "Hello, world!", 'o', result);

	// Test 2: Search for a character at the beginning of the string
	result = ft_strchr("Hello, world!", 'H');
	print_strchr_result(2, "Hello, world!", 'H', result);

	// Test 3: Search for a character at the end of the string
	result = ft_strchr("Hello, world!", '!');
	print_strchr_result(3, "Hello, world!", '!', result);

	// Test 4: Search for a character that is not in the string
	result = ft_strchr("Hello, world!", 'x');
	print_strchr_result(4, "Hello, world!", 'x', result);

	// Test 5: Search for the null terminator '\0'
	result = ft_strchr("Hello, world!", '\0');
	print_strchr_result(5, "Hello, world!", '\0', result);

	return (0);
} */