
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*## Function: `ft_isascii`

 The `ft_isprint` function checks whether the given character `c` is a printable
 ASCII character. Printable characters include all characters that have 
 a visible representation, such as letters, digits, punctuation marks, and 
 the space character (ASCII values from `32` to `126`).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a printable character (a character between 
 ASCII 32 and 126), the function returns a non-zero value (true).
 - Zero: If `c` is not a printable character, the function returns 0 (false).
 
### Important notes:
 - The function only considers characters in the standard printable ASCII
 range (32 to 126). Non-printable characters, such as control characters 
 (ASCII 0 to 31), and extended characters (above 126) will return false.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_isprint.c -L lib -lft -o test/test_ft_isprint

// ### Examples of usage:
/* #include <libft.h>		// For size_t
#include <ctype.h>		// For the standard isprint function
#include <stdio.h>		// For printf

// Structure to hold individual test cases
typedef struct	s_test_case
{
	int			input;
	const char	*description;
}				t_test_case;

int	main(void)
{
	t_test_case tests[] = {
		{ 'A', "Uppercase letter" },
		{ 'm', "Lowercase letter" },
		{ '5', "Digit" },
		{ '.', "Punctuation" },
		{ ' ', "Whitespace" },
		{ 31, "Non-printable control character (31)" },
		{ 126, "Tilde character (126)" },
		{ 127, "DEL character (127)" },
		{ 128, "Extended ASCII character (128)" },
		{ 255, "Extended ASCII character (255)" },
		{ -1, "Negative value (-1)" },
		{ '\0', "Null character '\\0'" },
		{ '\n', "Newline character '\\n'" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	int		result_ft;
	int		result_std;

	printf("Testing ft_isprint against standard isprint:\n");
	printf("---------------------------------------------------------------------\n");
	printf("%-5s | %-10s | %-10s | %-10s | %s | %s\n", "Test", "Input", "ft_isprint", "isprint", "Result", "Description");
	printf("---------------------------------------------------------------------\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		result_ft = ft_isprint(tests[i].input);
		result_std = isprint(tests[i].input);
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
}
 */