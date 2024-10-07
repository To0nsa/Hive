
#include <libft.h>

static int	ft_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static size_t	ft_trim_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_trim_end(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && ft_is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set);
	if (start >= end)
	{
		trimmed_str = (char *)malloc(sizeof(char));
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, s1 + start, end - start);
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}

/*## Function: ft_strtrim
### Prototype:
 `char	*ft_strtrim(const char *s1, const char *set)`

### Helper functions prototypes:
 `static int		ft_is_in_set(char c, const char *set)`
 `static size_t		ft_trim_start(const char *s1, const char *set)`
 `static size_t		ft_trim_end(const char *s1, const char *set)`
 `static char		*ft_strncpy(char *dest, const char *src, size_t n)`

### Description:
 The `ft_strtrim` function trims the characters from the string `s1` that are 
 present in the set `set`. It removes characters from both the beginning and the 
 end of the string, returning a newly allocated trimmed string.

### Parameters:
 - `const char *s1`: A pointer to the original string that will be trimmed.
 - `const char *set`: A pointer to the string containing the characters to be 
 removed from both the beginning and end of `s1`.

### Return:
 - Returns a pointer to the newly allocated trimmed string.
 - If memory allocation fails or if either `s1` or `set` is `NULL`, the function 
 returns `NULL`.
 - If all characters are trimmed, the function returns an empty string 
 (allocated with `malloc`).

### Details:
 - The function first checks if the input strings `s1` or `set` are `NULL`, and if 
 so, returns `NULL`.
 - It uses the helper function `ft_trim_start` to find the first position in `s1` 
 that is not part of `set`.
 - It then calls `ft_trim_end` to find the last valid character of `s1` not 
 contained in `set`.
 - If the `start` index is greater than or equal to the `end` index, the function 
 allocates an empty string and returns it.
 - The function allocates memory for the trimmed substring (`end - start + 1`) and 
 copies the relevant portion using `ft_strncpy`.
 - The resulting string is null-terminated before being returned.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the trimmed 
 string to avoid memory leaks.
 - If all characters in the input string are part of the set, the function returns 
 an empty string, not `NULL`.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strtrim.c -L lib -lft -o test/test_ft_strtrim

// ### Examples of usage
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strtrim
char	*ft_strtrim(const char *s1, const char *set);

// Struct to hold test case information
typedef struct	s_test_case
{
	const char	*input_str;
	const char	*set;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"  Hello World  ", " ", "Hello World", "Trim spaces from both sides"},
		{"---Hello World---", "-", "Hello World", "Trim dashes from both sides"},
		{"***Hello World", "*", "Hello World", "Trim asterisks from the beginning"},
		{"Hello World***", "*", "Hello World", "Trim asterisks from the end"},
		{"!!Hello!!World!!", "!", "Hello!!World", "Trim exclamation marks from both sides"},
		{"No trim needed", "xyz", "No trim needed", "No characters to trim"},
		{"   ", " ", "", "String of spaces, all trimmed"},
		{"abcdef", "abcdef", "", "Entire string matches the set, should result in empty string"},
		{"", "abc", "", "Empty input string"},
		{"Hello", "", "Hello", "Empty set, no trimming should occur"},
		{"   \t\nHello World\n\t   ", " \t\n", "Hello World", "Trim whitespace characters from both sides"}
	};
	int	num_tests = 11;
	int	i = 0;

	printf("\n\033[4mTesting ft_strtrim :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*result;

		// Call ft_strtrim with the current input
		result = ft_strtrim(tests[i].input_str, tests[i].set);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input String: \"%s\"\n", tests[i].input_str);
		printf("Set: \"%s\"\n", tests[i].set);
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
}