
#include <libft.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	copy = (char *)malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}

/*## Function: ft_strdup
### Prototype:
 `char	*ft_strdup(const char *src)`

### Helper function prototype:
 `static char	*ft_strcpy(char *dest, const char *src)`

### Description:
 The `ft_strdup` function allocates memory and returns a duplicate of the input 
 string `src`. The function copies the contents of `src`, including the null 
 terminator, to the newly allocated memory.

### Parameters:
 - `const char *src`: A pointer to the string that will be duplicated.

### Return:
 - Returns a pointer to the newly allocated string that is a duplicate of `src`.
 - If memory allocation fails, the function returns `NULL`.

### Details:
 - The function first calculates the len of `src` using `ft_strlen`.
 - It allocates memory sufficient to store `src`, including the null terminator.
 - The function uses `ft_strcpy` to copy the contents of `src` to the allocated memory.
 - The function returns a pointer to the newly allocated string.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the duplicate 
 string to avoid memory leaks.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strdup.c -L lib -lft -o test/test_ft_strdup

// ### Examples of usage:
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strdup
char	*ft_strdup(const char *src);

// Function to print the result of ft_strdup and compare with the original
void	print_strdup_result(int test_number, const char *src, char *result)
{
	printf("\033[4mTest %d:\033[0m Duplicating \"%s\"\n", test_number, src);

	if (result != NULL)
		printf("        Duplicate: \"%s\"\n", result);
	else
		printf("        Duplicate: NULL (Memory allocation failed)\n");

	printf("\n");
}

int	main(void)
{
	char *result;

	printf("\n\033[4mTesting ft_strdup :\033[0m\n\n");

	// Test 1: Duplicating a normal string
	result = ft_strdup("Hello, world!");
	print_strdup_result(1, "Hello, world!", result);
	free(result);

	// Test 2: Duplicating an empty string
	result = ft_strdup("");
	print_strdup_result(2, "", result);
	free(result);

	// Test 3: Duplicating a string with special characters
	result = ft_strdup("~!@#$%^&*()_+");
	print_strdup_result(3, "~!@#$%^&*()_+", result);
	free(result);

	// Test 4: Duplicating a numeric string
	result = ft_strdup("1234567890");
	print_strdup_result(4, "1234567890", result);
	free(result);

	// Test 5: Passing NULL to ft_strdup (should return NULL)
	result = ft_strdup(NULL);
	print_strdup_result(5, "(NULL input)", result);

	return (0);
}