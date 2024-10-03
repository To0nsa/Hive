
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*## Function: `ft_isascii`

 The `ft_isascii` function checks whether the given character `c` is an ASCII character.
 ASCII (American Standard Code for Information Interchange) is a character encoding
 standard that represents text characters in the range of `0` to `127`.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a valid ASCII character (i.e., it falls within the range
 of 0 to 127), the function returns a non-zero value (true).
 - Zero: If c is outside the ASCII range (i.e., less than 0 or greater than 127),
 the function returns 0 (false).
 
### Important notes:
 - The function specifically checks for the ASCII range (0–127). Characters outside
 this range (such as extended ASCII or Unicode characters) will return false.*/

// ### Examples of usage:
#include <libft.h>     // For size_t
#include <ctype.h>     // For the standard isascii function
#include <stdio.h>     // For printf

// Structure to hold individual test cases
typedef struct	s_test_case
{
	int			input;
	const char	*description;
}				t_test_case;

int	main(void)
{
	t_test_case tests[] = {
		{ 'A', "Uppercase Letter" },
		{ 'm', "Lowercase Letter" },
		{ '5', "Digit" },
		{ '.', "Punctuation" },
		{ ' ', "Whitespace" },
		{ 127, "DEL Character (127)" },
		{ 128, "Extended ASCII Character (128)" },
		{ 255, "Extended ASCII Character (255)" },
		{ -1, "Negative Value (-1)" },
		{ '\0', "Null Character '\\0'" },
		{ '\n', "Newline Character '\\n'" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	int		result_ft;
	int		result_std;

	printf("Testing ft_isascii against standard isascii:\n");
	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		result_ft = ft_isascii(tests[i].input);
		result_std = isascii(tests[i].input);
		printf("Test %2zu: Input = ", i + 1);

		// Print character representation safely
		if (tests[i].input >= 32 && tests[i].input <= 126)
			printf("'%c'", tests[i].input);
		else if (tests[i].input == '\0')
			printf("'\\0'");
		else if (tests[i].input == '\n')
			printf("'\\n'");
		else
			printf("%d", tests[i].input);
		printf(" | ft_isascii: %d | isascii: %d | [", result_ft, result_std);

		// Determine PASS or FAIL
		if ((result_ft != 0 && result_std != 0) || (result_ft == 0 && result_std == 0))
			printf("PASS");
		else
			printf("FAIL");
		printf("] - %s\n", tests[i].description);
		i++;
	}
	return (0);
}