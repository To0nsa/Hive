 
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*## Function: ft_isalpha

 The ft_isalpha function checks whether the given character `c` is an alphabetic
 character. An alphabetic character is defined as any uppercase letter (A to Z)
 or lowercase letter (a to z).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is an alphabetic character (either uppercase 
 or lowercase), the function returns a non-zero value (true).
 - Zero: If c is not an alphabetic character, the function returns 0.

### Important notes:
 - This function assumes that the input is representable as an `unsigned char` or `EOF`.
 Passing a value outside this range may lead to undefined behavior.
 - This function does not account for any locale-specific alphabetic characters
 (e.g., accented letters). It only works for standard ASCII alphabetic characters. */

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_isalpha.c -L lib -lft -o test/test_ft_isalpha

// ###Examples of usage:
/* #include <libft.h>		// For size_t
#include <ctype.h>		// For the standard isalpha function
#include <stdio.h>		// For printf

// Structure to hold individual test cases
typedef struct	s_test_case
{
	int			input;
	const char	*description;
}				t_test_case;

int main(void)
{
	t_test_case tests[] = {
		{ 'A', "Uppercase letter" },
		{ 'm', "Lowercase letter" },
		{ '5', "Digit" },
		{ '.', "Punctuation" },
		{ ' ', "Whitespace" },
		{ 128, "Extended ASCII character (128)" },
		{ 255, "Extended ASCII character (255)" },
		{ '\0', "Null character '\\0'" },
		{ '\n', "Newline character '\\n'" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	int		result_ft;
	int		result_std;

	printf("Testing ft_isalpha against standard isalpha:\n");
	printf("---------------------------------------------------------------------\n");
	printf("%-5s | %-10s | %-10s | %-10s | %s | %s\n", "Test", "Input", "ft_isalpha", "isalpha", "Result", "Description");
	printf("---------------------------------------------------------------------\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		result_ft = ft_isalpha(tests[i].input);
		result_std = isalpha(tests[i].input);
		printf("%-5zu | ", i + 1);

		// Print character representation safely
		if (tests[i].input >= 32 && tests[i].input <= 126)
			printf("'%c'        | ", tests[i].input);
		else if (tests[i].input == '\0')
			printf("'\\0'       | ");
		else if (tests[i].input == '\n')
			printf("'\\n'       | ");
		else
			printf("%-10d | ", tests[i].input);
		printf("%-10d | %-10d | ", result_ft, result_std);

		// Determine PASS or FAIL
		if ((result_ft != 0 && result_std != 0) || (result_ft == 0 && result_std == 0))
			printf("PASS");
		else
			printf("FAIL");

		// Print description
		printf("   | %s\n", tests[i].description);
		i++;
	}
	printf("---------------------------------------------------------------------\n");
	return (0);
} */