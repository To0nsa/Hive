
#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}

/*## Function: ft_strncmp
### Prototype:
 `int	ft_strncmp(const char *s1, const char *s2, size_t n)`

### Description:
 The `ft_strncmp` function compares up to `n` characters of the strings `s1` and
 `s2`. It performs a lexicographical comparison and returns an integer less than,
 equal to, or greater than zero, depending on whether `s1` is found to be less
 than, equal to, or greater than `s2`.

### Parameters:
 - `const char *s1`: The first string to be compared.
 - `const char *s2`: The second string to be compared.
 - `size_t n`: The maximum number of characters to compare.

### Return:
 - Returns an integer less than zero if `s1` is less than `s2`.
 - Returns zero if `s1` is equal to `s2`.
 - Returns an integer greater than zero if `s1` is greater than `s2`.

### Details:
 - The comparison is performed using unsigned characters to ensure that characters
 with values greater than 127 are handled correctly.
 - The function iterates through both strings, comparing characters one by one up
 to `n` characters or until a null terminator is encountered.
 - If a difference is found between the characters, the function returns the
 difference between the first two differing characters.
 - If the strings are equal for the first `n` characters, the function returns `0`.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strncmp.c -L lib -lft -o test/test_ft_strncmp

// ### Examples of usage
#include <libft.h>  // Ensure your libft header is included
#include <stdio.h>

// Prototype of ft_strncmp
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// Struct to hold test case information
typedef struct	s_test_case
{
	const char	*s1;
	const char	*s2;
	size_t		n;
	int			expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"Hello", "Hello", 5, 0, "Identical strings with full length"},
		{"Hello", "HelloWorld", 5, 0, "Identical strings up to length n"},
		{"Hello", "HelloWorld", 10, -1, "First string shorter than second string"},
		{"Hello", "Hellz", 5, -1, "Strings differ at the last character"},
		{"Hello", "Hella", 4, 0, "Strings identical up to length n"},
		{"Hello", "hello", 5, -32, "Case-sensitive comparison"},
		{"Hello", "", 5, 'H', "Comparison with an empty string"},
		{"", "", 1, 0, "Both strings are empty"},
		{"Hello", "Hellz", 3, 0, "Identical up to n but different afterward"},
		{"1234", "1235", 4, -1, "Numeric characters comparison"},
		{"\n\t", "\n\t", 2, 0, "Non-printable characters comparison"},
		{"Hello", "Hellp", 6, -1, "Different at the fifth character"},
		{"abcd", "abcd", 0, 0, "Zero-length comparison"},
	};
	int	num_tests = 13;
	int	i = 0;

	printf("\n\033[4mTesting ft_strncmp :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		int	result;

		// Call ft_strncmp with the current input
		result = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("String 1: \"%s\"\n", tests[i].s1);
		printf("String 2: \"%s\"\n", tests[i].s2);
		printf("Length n: %zu\n", tests[i].n);
		printf("Expected Result: %d\n", tests[i].expected_result);
		printf("Actual Result: %d\n", result);

		// Check if the result matches the expected value
		if ((result == 0 && tests[i].expected_result == 0) ||
			(result < 0 && tests[i].expected_result < 0) ||
			(result > 0 && tests[i].expected_result > 0))
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
}