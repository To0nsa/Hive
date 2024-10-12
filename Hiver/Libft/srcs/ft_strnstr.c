
#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*## Function: ft_strnstr
### Prototype:
 `char	*ft_strnstr(const char *big, const char *little, size_t len)`

### Description:
 The `ft_strnstr` function locates the first occurrence of the substring `little`
 in the string `big`, where no more than `len` characters are searched. If 
 `little` is an empty string, `big` is returned. If `little` is not found 
 within `len` characters, the function returns `NULL`.

### Parameters:
 - `const char *big`: The string in which to search for `little`.
 - `const char *little`: The substring to search for.
 - `size_t len`: The maximum number of characters to search.

### Return:
 - Returns a pointer to the first occurrence of `little` in `big` if found.
 - If `little` is an empty string, the function returns `big`.
 - If `little` is not found within the first `len` characters, the function 
 returns `NULL`.

### Details:
 - If `little` is an empty string, `big` is returned immediately.
 - The function searches for the substring `little` in `big` while ensuring 
 that it doesn't search beyond the first `len` characters.
 - The function compares characters of `little` to `big`, checking for a match.
 - If a match is found within the given limit (`len`), a pointer to the start of 
 the match is returned.
 - If no match is found or if `len` is too small, the function returns `NULL`.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strnstr.c -L lib -lft -o test/test_ft_strnstr

// ### Examples of usage
/* #include <libft.h>
#include <stdio.h>

// Prototype of ft_strnstr
char	*ft_strnstr(const char *big, const char *little, size_t len);

// Struct to hold test case information
typedef struct	s_test_case
{
	const char	*big;
	const char	*little;
	size_t		len;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"Hello, World!", "World", 13, "World!", "Substring found within range"},
		{"Hello, World!", "World", 5, NULL, "Substring not found due to length limit"},
		{"Hello, World!", "", 5, "Hello, World!", "Empty substring should return the big string"},
		{"Hello, World!", "Hello", 5, "Hello, World!", "Substring matches the beginning of the string"},
		{"Hello, World!", "hello", 13, NULL, "Case-sensitive search should fail"},
		{"abcdef", "cde", 6, "cdef", "Substring in the middle of the string"},
		{"abcdef", "cde", 3, NULL, "Substring not found due to length limit"},
		{"abcdef", "xyz", 6, NULL, "Substring not found at all"},
		{"abcdef", "ef", 6, "ef", "Substring at the end of the string"},
		{"abcdef", "", 0, "abcdef", "Empty substring with zero length"},
		{"a", "a", 1, "a", "Single character match"},
		{"", "a", 1, NULL, "Empty big string"},
		{"abcdef", "abcdef", 3, NULL, "Substring is longer than length limit"}
	};
	int	num_tests = 13;
	int	i = 0;

	printf("\n\033[4mTesting ft_strnstr :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*result;

		// Call ft_strnstr with the current input
		result = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Big String: \"%s\"\n", tests[i].big);
		printf("Little String: \"%s\"\n", tests[i].little);
		printf("Length: %zu\n", tests[i].len);
		printf("Expected Result: \"%s\"\n", tests[i].expected_result ? tests[i].expected_result : "NULL");
		printf("Actual Result: \"%s\"\n", result ? result : "NULL");

		// Check if the result matches the expected value
		if ((result == NULL && tests[i].expected_result == NULL) ||
			(result != NULL && tests[i].expected_result != NULL &&
			ft_strncmp(result, tests[i].expected_result, ft_strlen(tests[i].expected_result)) == 0))
		{
			printf("Result: \033[32mPASS\033[0m - %s\n", tests[i].description);
		}
		else
		{
			printf("Result: \033[31mFAIL\033[0m - %s\n", tests[i].description);
		}
		printf("---------------------------\n");
		i++;
	}
	return 0;
} */