
#include <libft.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

/*## Function: ft_strjoin
### Prototype:
 `char	*ft_strjoin(const char *s1, const char *s2)`

### Helper function prototype:
 `static char	*ft_strcpy(char *dest, const char *src)`

### Description:
 The `ft_strjoin` function concatenates two strings, `s1` and `s2`, into a new 
 string. The function allocates memory for the new string, copies `s1` followed 
 by `s2`, and returns the result. The resulting string is null-terminated.

### Parameters:
 - `const char *s1`: A pointer to the first string to be joined.
 - `const char *s2`: A pointer to the second string to be joined.

### Return:
 - Returns a pointer to the newly allocated string that contains the concatenation
 of `s1` and `s2`.
 - If memory allocation fails or if either `s1` or `s2` is `NULL`, the function 
 returns `NULL`.

### Details:
 - The function first checks if either `s1` or `s2` is `NULL`. If either is 
 `NULL`, the function returns `NULL`.
 - It calculates the total length of the new string by adding the lengths of `s1` 
 and `s2` using `ft_strlen`.
 - Memory is allocated for the new string, with enough space for both strings and 
 the null terminator.
 - The function uses the helper `ft_strcpy` to copy `s1` to the new string.
 - It then appends `s2` to the new string by copying it right after the end of `s1`.
 - The new string is null-terminated and returned to the caller.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the resulting 
 string to avoid memory leaks.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strjoin.c -L lib -lft -o test/test_ft_strjoin

// ### Examples of usage:
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strjoin
char	*ft_strjoin(const char *s1, const char *s2);

// Function to test and display results of ft_strjoin
void	test_ft_strjoin(const char *s1, const char *s2, int test_number)
{
	char	*result;

	printf("\033[4mTest %d:\033[0m Joining \"%s\" and \"%s\"\n", test_number, s1, s2);
	result = ft_strjoin(s1, s2);
	if (result != NULL)
	{
		printf("        Result: \"%s\"\n", result);
		free(result);
	}
	else
	{
		printf("        Result: NULL (Memory allocation failed or NULL input)\n");
	}
	printf("\n");
}

// Main function to run the tests
int	main(void)
{
	printf("\n\033[4mTesting ft_strjoin :\033[0m\n\n");

	// Test 1: Joining two normal strings
	test_ft_strjoin("Hello", " World", 1);

	// Test 2: Joining with an empty string
	test_ft_strjoin("Hello", "", 2);

	// Test 3: Joining two empty strings
	test_ft_strjoin("", "", 3);

	// Test 4: Joining one empty string with a normal string
	test_ft_strjoin("", "World", 4);

	// Test 5: Joining two strings with special characters
	test_ft_strjoin("Special@#", "$Char%&*", 5);

	// Test 6: Joining large strings
	test_ft_strjoin("This is a long string of text", " followed by another long string of text.", 6);

	// Test 7: Handling NULL inputs (should return NULL)
	test_ft_strjoin(NULL, "World", 7);
	test_ft_strjoin("Hello", NULL, 8);
	test_ft_strjoin(NULL, NULL, 9);

	return (0);
}
