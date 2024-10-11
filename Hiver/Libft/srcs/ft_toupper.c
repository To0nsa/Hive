
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

/*## Function: `ft_toupper`

 The `ft_toupper` function converts a lowercase alphabetic character to
 its corresponding uppercase equivalent. If the input character `c` is an
 lowercase letter (`'a'` to `'z'`), it is converted to the corresponding uppercase
 letter. If `c` is not an lowercase letter, it is returned unchanged. 

### Parameters:
 - `int c`: The character to be converted. The argument is typically passed as 
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - If `c` is a lowercase letter, the function returns the corresponding uppercase letter.
 - If `c` is not an lowercase letter, the function returns `c` unchanged.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_toupper.c -L lib -lft -o test/test_ft_toupper

// ### Examples of usage
/* #include <libft.h>
#include <stdio.h>

// Prototype of ft_toupper
int	ft_toupper(int c);

typedef struct	s_test_case
{
	int		input_char;
	int		expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	t_test_case tests[] = {
		{'a', 'A', "Lowercase a to uppercase A"},
		{'z', 'Z', "Lowercase z to uppercase Z"},
		{'m', 'M', "Lowercase m to uppercase M"},
		{'A', 'A', "Uppercase A, should remain the same"},
		{'Z', 'Z', "Uppercase Z, should remain the same"},
		{'0', '0', "Digit 0, should remain the same"},
		{'!', '!', "Punctuation mark '!', should remain the same"},
		{' ', ' ', "Whitespace character, should remain the same"},
		{128, 128, "Non-ASCII character (128), should remain the same"},
		{'\n', '\n', "Newline character, should remain the same"}
	};
	int	num_tests = 10;
	int	i = 0;

	printf("\n\033[4mTesting ft_toupper :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		int	result;

		result = ft_toupper(tests[i].input_char);

		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input Character: '%c' (ASCII: %d)\n", tests[i].input_char, tests[i].input_char);
		printf("Expected Result: '%c' (ASCII: %d)\n", tests[i].expected_result, tests[i].expected_result);
		printf("Actual Result: '%c' (ASCII: %d)\n", result, result);

		if (result == tests[i].expected_result)
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
	return (0);
} */