
#include <libft.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*substr;
	size_t			str_len;
	size_t			max_len;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	substr = (char *)malloc((max_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, str + start, max_len + 1);
	return (substr);
}

/*## Function: ft_substr
### Prototype:
 `char	*ft_substr(const char *str, unsigned int start, size_t len)`

### Helper functions prototypes:
 `static char	*ft_strncpy(char *dest, const char *src, size_t n)`

### Description:
 The `ft_substr` function creates a new substring from the string `str`, starting
 at a specified index `start` and with a specified maximum length `len`. The 
 function allocates memory for the new substring and ensures it is null-terminated.

### Parameters:
 - `const char *str`: A pointer to the original string from which the substring 
 will be extracted.
 - `unsigned int start`: The starting index in `str` where the substring begins.
 - `size_t len`: The maximum length of the substring.

### Return:
 - Returns a pointer to the newly allocated substring.
 - If memory allocation fails or if the input string `str` is `NULL`, the function 
 returns `NULL`.
 - If the `start` index is beyond the length of `str`, the function returns an 
 empty string (allocated with `malloc`).

### Details:
 - The function first checks if the input string `str` is `NULL`, returning `NULL` 
 if so.
 - It calculates the length of `str` using `ft_strlen`.
 - If the `start` index is greater than or equal to the length of `str`, the 
 function allocates memory for an empty string and returns it.
 - It calculates the maximum possible length of the substring (`max_len`), which 
 is the lesser of `len` or the remaining characters after the `start` index.
 - Memory is allocated for the substring (`max_len + 1` to account for the null 
 terminator).
 - The function copies the relevant portion of the string using `ft_strncpy`.
 - The substring is null-terminated before being returned.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the substring 
 to avoid memory leaks.
 - If the `start` index is greater than or equal to the length of `str`, the 
 function returns an empty string, not `NULL`.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_substr.c -L lib -lft -o test/test_ft_substr

// Examples of usage
/* #include <libft.h>
#include <stdio.h>

// Prototype of ft_substr
char	*ft_substr(const char *str, unsigned int start, size_t len);

// Struct to hold test case information
typedef struct	s_test_case
{
	const char	*input_str;
	unsigned int start;
	size_t		len;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"Hello, World!", 7, 5, "World", "Substring starting at index 7, length 5"},
		{"Hello, World!", 0, 5, "Hello", "Substring from the beginning of the string"},
		{"Hello, World!", 0, 20, "Hello, World!", "Substring longer than string length"},
		{"Hello, World!", 13, 5, "", "Start index beyond string length"},
		{"Hello, World!", 7, 0, "", "Zero length, should return an empty string"},
		{"Hello, World!", 5, 1, ",", "Single character substring"},
		{"", 0, 5, "", "Empty input string"},
		{"Hello, World!", 5, 100, ", World!", "Length greater than remaining part of the string"},
		{"1234567890", 9, 1, "0", "Last character of the string"},
		{"Edge cases", 9, 5, "s", "Length longer than available but within bounds"}
	};
	int	num_tests = 10;
	int	i = 0;

	printf("\n\033[4mTesting ft_substr :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*result;

		// Call ft_substr with the current input
		result = ft_substr(tests[i].input_str, tests[i].start, tests[i].len);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input String: \"%s\"\n", tests[i].input_str);
		printf("Start Index: %u\n", tests[i].start);
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

		// Free dynamically allocated memory
		free(result);
		i++;
	}
	return 0;
} */