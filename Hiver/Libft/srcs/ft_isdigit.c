
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*## Function: `ft_isdigit`

 The `ft_isdigit` function checks whether the given character c is
 a decimal digit (i.e., a number from `'0'` to `'9'`).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a digit (a character between `'0'` and `'9'`),
 the function returns a non-zero value (true).
 - Zero: If `c` is not a digit, the function returns 0.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_isdigit.c -L lib -lft -o test/test_ft_isdigit

// ###Examples of usage:
/* #include <libft.h>		// For size_t
#include <ctype.h>		// For the standard isdigit function
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
		{ '0', "Digit '0'" },
		{ '5', "Digit '5'" },
		{ '9', "Digit '9'" },
		{ 'a', "Lowercase letter 'a'" },
		{ 'Z', "Uppercase letter 'Z'" },
		{ '.', "Punctuation '.'" },
		{ ' ', "Whitespace ' '" },
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
	
	printf("Testing ft_isdigit against standard isdigit:\n");
	printf("---------------------------------------------------------------------\n");
	printf("%-5s | %-10s | %-10s | %-10s | %s | %s\n", "Test", "Input", "ft_isdigit", "isdigit", "Result", "Description");
	printf("---------------------------------------------------------------------\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		result_ft = ft_isdigit(tests[i].input);
		result_std = isdigit(tests[i].input);
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