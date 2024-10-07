
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}

/*## Function: `ft_tolower`

 The `ft_tolower` function converts an uppercase alphabetic character to
 its corresponding lowercase equivalent. If the input character `c` is an
 uppercase letter (`'A'` to `'Z'`), it is converted to the corresponding lowercase
 letter. If `c` is not an uppercase letter, it is returned unchanged. 

### Parameters:
 - `int c`: The character to be converted. The argument is typically passed as 
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - If `c` is an uppercase letter, the function returns the corresponding lowercase letter.
 - If `c` is not an uppercase letter, the function returns `c` unchanged.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_tolower.c -L lib -lft -o test/test_ft_tolower

// Example of usage
#include <libft.h>
#include <stdio.h>

// Prototype of ft_tolower
int	ft_tolower(int c);

// Struct to hold test case information
typedef struct	s_test_case
{
	int		input_char;
	int		expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{'A', 'a', "Uppercase A to lowercase a"},
		{'Z', 'z', "Uppercase Z to lowercase z"},
		{'M', 'm', "Uppercase M to lowercase m"},
		{'a', 'a', "Lowercase a, should remain the same"},
		{'z', 'z', "Lowercase z, should remain the same"},
		{'0', '0', "Digit 0, should remain the same"},
		{'!', '!', "Punctuation mark '!', should remain the same"},
		{' ', ' ', "Whitespace character, should remain the same"},
		{128, 128, "Non-ASCII character (128), should remain the same"},
		{'\n', '\n', "Newline character, should remain the same"}
	};
	int	num_tests = 10;
	int	i = 0;

	printf("\n\033[4mTesting ft_tolower :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		int	result;

		// Call ft_tolower with the current input
		result = ft_tolower(tests[i].input_char);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input Character: '%c' (ASCII: %d)\n", tests[i].input_char, tests[i].input_char);
		printf("Expected Result: '%c' (ASCII: %d)\n", tests[i].expected_result, tests[i].expected_result);
		printf("Actual Result: '%c' (ASCII: %d)\n", result, result);

		// Check if the result matches the expected value
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

	return 0;
}
 