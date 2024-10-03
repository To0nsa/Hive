
#include <libft.h>

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*## Function: `ft_isalnum`

 The `ft_isalnum` function checks whether the given character `c` is an alphanumeric
 character. An alphanumeric character is defined as either a letter (alphabetic 
 character) or a digit (numeric character). This function relies on two other
 functions: `ft_isalpha` (to check if `c` is a letter) and `ft_isdigit` (to check if `c` 
 is a digit).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is either a letter (A-Z, a-z) or a digit (0-9), 
 the function returns a non-zero value.
 - Zero: If `c` is neither a letter nor a digit, the function returns 0.
 
### Important notes:
 - This function assumes that the input is representable as an `unsigned char` or is `EOF`.
 Passing a value outside this range may lead to undefined behavior.*/

//### Examples of usage:
#include <ctype.h>		// For the standard isalnum function
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
		{ 'A', "Uppercase Letter" },
		{ 'm', "Lowercase Letter" },
		{ '5', "Digit" },
		{ '.', "Punctuation" },
		{ ' ', "Whitespace" },
		{ 128, "Extended ASCII Character (128)" },
		{ 255, "Extended ASCII Character (255)" },
		{ '\0', "Null Character '\\0'" },
		{ '\n', "Newline Character '\\n'" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	int		result_ft;
	int		result_std;
	
	printf("Testing ft_isalnum against standard isalnum:\n");
	printf("------------------------------------------------------------\n");
	printf("%-5s | %-10s | %-10s | %-10s | %s & %s\n", "Test", "Input", "ft_isalnum", "isalnum", "Result", "Description");
	printf("------------------------------------------------------------\n");
	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		result_ft = ft_isalnum(tests[i].input);
		result_std = isalnum(tests[i].input);
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
		printf(" - %s\n", tests[i].description);
		i++;
	}
	return (0);
}
