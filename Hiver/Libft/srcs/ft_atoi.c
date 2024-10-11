
#include "libft.h"

int	ft_isdigit(int c);

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/*## Function: ft_atoi
### Prototype:
 `int	ft_atoi(const char *str)`

### Description:
 The `ft_atoi` function converts a string representing an integer into an actual
 integer. It handles leading whitespace, an optional sign, and uses string 
 arithmetic (character-by-character manipulation) to compute the final integer 
 value.

### Parameters:
 - `const char *str`: The string to be converted into an integer.

### Return:
 - Returns the integer value obtained from the conversion of the string `str`.
 - If the string does not contain valid numeric digits, the function returns `0`.

### Details:
 - The function skips any leading whitespace (spaces, tabs, etc.) and handles 
 the optional sign (`'+'` or `'-'`).
 - Using string arithmetic, it converts each digit from `'0'` to `'9'` to its 
 corresponding integer value by subtracting `'0'` from the character's ASCII value.
 - The function accumulates the result, multiplying the existing value by 10 
 before adding the next digit.
 - The function applies the appropriate sign at the end and returns the result.

### Important notes:
 - The function assumes that the input is a null-terminated string.
 - It does not handle overflow/underflow conditions.
 - If the input string doesn't contain any valid numbers, the function returns `0`.

### Examples of usage:
 1- Command-Line argument conversion: When converting command-line arguments 
 (e.g., argv in main) to integers, assuming the input is correctly formatted.

 2- Simple configuration parsing: When parsing simple configuration strings where 
 numeric values are provided directly and expected to be valid.

 3- Data extraction from a string: Converting known numeric substrings extracted from
 a formatted string (e.g., extracting an ID or count).

 4- Parsing numbers from a file: If reading data from a file where numeric strings are
 guaranteed to be valid (e.g., a file with structured integer values).*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include srcs/ft_atoi.c -L lib -lft -o test/test_ft_atoi

/* #include "libft.h"
#include <stdio.h>
#include <limits.h>

// Prototype of ft_atoi
int	ft_atoi(const char *str);

typedef struct	s_test_case
{
	const char	*str;
	int			expected;
	const char	*description;
}				t_test_case;

int	main(void)
{
	t_test_case tests[] = {
		{"42", 42, "Simple positive number"},
		{"-42", -42, "Simple negative number"},
		{"   123", 123, "Leading spaces"},
		{"   -123", -123, "Leading spaces with negative sign"},
		{"+123", 123, "Positive sign"},
		{"0", 0, "Zero"},
		{"-0", 0, "Negative zero"},
		{"2147483647", INT_MAX, "Maximum int"},
		{"-2147483648", INT_MIN, "Minimum int"},
		{"   +000123", 123, "Leading zeros and spaces"},
		{"123abc", 123, "Invalid characters after number"},
		{"abc123", 0, "Invalid characters before number"},
		{"   +   123", 0, "Invalid characters in between"},
		{"", 0, "Empty string"},
		{"++++123", 0, "Multiple signs"},
		{"2147483648", INT_MAX, "Overflow beyond INT_MAX"},
		{"-2147483649", INT_MIN, "Underflow beyond INT_MIN"},
	};
	
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	i = 0;

	printf("\033[4mTesting ft_atoi:\033[0m\n\n");

	while (i < num_tests)
	{
		int	result = ft_atoi(tests[i].str);
		int	pass = 0;

		if (result == tests[i].expected)
			pass = 1;
		else
			pass = 0;

		printf("\033[4mTest %d:\033[0m %s\n", i + 1, tests[i].description);
		printf("Input: '%s'\n", tests[i].str);
		printf("Expected Output: %d\n", tests[i].expected);
		printf("Actual Output:   %d\n", result);

		if (pass)
			printf("Result: \033[32mPASS\033[0m\n");
		else
			printf("Result: \033[31mFAIL\033[0m\n");
		printf("---------------------------\n");
		i++;
	}
	return (0);
}
 */