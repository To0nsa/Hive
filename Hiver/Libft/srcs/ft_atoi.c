
#include <libft.h>

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
 - If the input string doesn't contain any valid numbers, the function returns `0`.*/

// ### Compile : 
// cc -Wall -Wextra -Werror -I include srcs/ft_atoi.c -L lib -lft -o test/test_ft_atoi

// ### Examples of usage:
#include <stdio.h>
int	main(void)
{
	const char *test_cases[] = {
		"42",			// Simple positive number
		"-42",			// Simple negative number
		"   123",		// Leading spaces
		"   -123",		// Leading spaces with negative sign
		"+123",			// Positive sign
		"0",			// Zero
		"-0",			// Negative zero
		"2147483647",	// Maximum int
		"-2147483648",	// Minimum int
		"   +000123",	// Leading zeros and spaces
		"123abc",		// Invalid characters after number
		"abc123",		// Invalid characters before number
		"   +   123",	// Invalid characters in between
		"",				// Empty string
		"++++123",		// Multiple signs
		NULL			// End of test cases
	};
	int i = 0;

	while (test_cases[i])
	{
		printf("Input:'%11s' -> Output: %d\n", test_cases[i], ft_atoi(test_cases[i]));
		i++;
	}
	return (0);
}