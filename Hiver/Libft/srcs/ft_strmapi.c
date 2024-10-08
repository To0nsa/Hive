
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t 	len;
	size_t 	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*## Function: ft_strmapi
### Prototype:
 `char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))`

### Description:
 The `ft_strmapi` function applies the function `f` to each character of the 
 string `s` to create a new string. The function `f` takes the index of the 
 character as its first argument and the character itself as the second argument.
 A new string is created with `malloc`, and each character is replaced by the 
 result of applying `f` to the corresponding character from `s`.

### Parameters:
 - `const char *s`: The string on which to iterate.
 - `char (*f)(unsigned int, char)`: A pointer to the function that is applied to 
 each character of the string. This function takes two parameters: an unsigned 
 integer (the index of the character) and the character itself.

### Return:
 - Returns a new string created by applying `f` to each character of `s`.
 - Returns `NULL` if memory allocation fails.

### Details:
 - The function first calculates the length of the string `s`.
 - Memory is allocated for the new string, which will have the same length as `s`.
 - The function iterates over the string `s`, applies the function `f` to each 
 character, and stores the result in the newly allocated string.
 - The function returns the newly created string, which is null-terminated.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the new string.
 - If `s` or `f` is `NULL`, the function returns `NULL`.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strmapi.c -L lib -lft -o test/test_ft_strmapi

// Examples of usage
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

// Prototype of ft_strmapi
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Example functions to use with ft_strmapi
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// Example functions to use with ft_strmapi
char	to_upper(unsigned int index, char c)
{
	(void)index; // Unused parameter
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

char	increment_char(unsigned int index, char c)
{
	(void)index; // Unused parameter
	return (c + 1);
}

char	shift_by_index(unsigned int index, char c)
{
	return (c + index);
}

// Struct to hold the test case information
typedef struct	s_test_case
{
	const char	*input;
	char		(*func)(unsigned int, char);
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"hello world", to_upper, "HELLO WORLD", "Convert all letters to uppercase"},
		{"abcdef", increment_char, "bcdefg", "Increment each character"},
		{"abcd", shift_by_index, "aceg", "Shift each character by its index"},
		{"1234", increment_char, "2345", "Increment numeric characters"},
		{"", to_upper, "", "Empty string test"},
		{"\n\t", increment_char, "\v\n", "Non-printable characters"},
		{"Zz", shift_by_index, "Z{", "Shift by index on mixed case"}
	};
	int	num_tests = 7;
	int	i = 0;

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*result;

		// Call ft_strmapi with the current input and function
		result = ft_strmapi(tests[i].input, tests[i].func);

		printf("\n\033[4mTesting ft_strmapi :\033[0m\n\n");

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input: \"%s\"\n", tests[i].input);
		printf("Expected Result: \"%s\"\n", tests[i].expected_result);
		printf("Actual Result: \"%s\"\n", result ? result : "NULL");

		// Check if the result matches the expected value using ft_strncmp
		if (result && tests[i].expected_result && 
			ft_strncmp(result, tests[i].expected_result, ft_strlen(tests[i].expected_result)) == 0)
			printf("Result: \033[32mPASS\033[0m - %s\n", tests[i].description);
		else if (!result && !tests[i].expected_result)
			printf("Result: \033[32mPASS\033[0m - %s\n", tests[i].description);
		else
			printf("Result: \033[31mFAIL\033[0m - %s\n", tests[i].description);
		printf("---------------------------\n");

		free(result);
		i++;
	}
	return (0);
}