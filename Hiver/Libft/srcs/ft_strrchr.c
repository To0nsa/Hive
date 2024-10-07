
#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;
	char	ch;

	ch = (char)c;
	last_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == ch)
			last_occurrence = (char *)str;
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (last_occurrence);
}

/*## Function: ft_strrchr
### Prototype:
 `char	*ft_strrchr(const char *s, int c)`

### Description:
 The `ft_strrchr` function locates the last occurrence of the character `c` 
 (converted to `char`) in the string `s`. The terminating null character is 
 considered part of the string, so if `c` is `'\0'`, the function returns a 
 pointer to the null terminator.

### Parameters:
 - `const char *str`: A pointer to the null-terminated string to be searched.
 - `int c`: The character to search for, passed as an `int`, but internally 
 cast to `char`.

### Return:
 - Returns a pointer to the last occurrence of the character `c` in the string `s`.
 - If the character `c` is not found in the string, the function returns `NULL`.

### Details:
 - The function first scans through the entire string `s` to locate the last 
 occurrence of the character `c`.
 - It checks for both regular characters and the null terminator `\0`, treating 
 the null terminator as part of the string.
 - Once the last occurrence is found, the function returns a pointer to it.
 - If the character `c` is not found, the function returns `NULL`.

### Important notes:
 - The function does not modify the string; it only returns a pointer to the 
 location of the character.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strrchr.c -L lib -lft -o test/test_ft_strrchr

// ### Examples of usage
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strrchr
char	*ft_strrchr(const char *str, int c);

// Struct to hold test case information
typedef struct	s_test_case
{
	const char	*str;
	int			c;
	const char	*expected_result;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"Hello, World!", 'o', "orld!", "Last occurrence of character in the middle of the string"},
		{"Hello, World!", 'l', "ld!", "Multiple occurrences of character, should return the last one"},
		{"Hello, World!", 'H', "Hello, World!", "Character at the beginning of the string"},
		{"Hello, World!", '!', "!", "Character at the end of the string"},
		{"Hello, World!", 'x', NULL, "Character not found in the string"},
		{"Hello, World!", '\0', "", "Search for null terminator"},
		{"", 'a', NULL, "Empty string, character not found"},
		{"", '\0', "", "Empty string, null terminator"},
		{"Mississippi", 's', "sippi", "Multiple occurrences of character, last occurrence expected"},
		{"abcdef", 'f', "f", "Last character match"},
	};
	int	num_tests = 10;
	int	i = 0;

	printf("\n\033[4mTesting ft_strrchr :\033[0m\n\n");

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		char	*result;

		// Call ft_strrchr with the current input
		result = ft_strrchr(tests[i].str, tests[i].c);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Input String: \"%s\"\n", tests[i].str);
		printf("Character to Find: '%c'\n", tests[i].c);
		printf("Expected Result: \"%s\"\n", tests[i].expected_result ? tests[i].expected_result : "NULL");
		printf("Actual Result: \"%s\"\n", result ? result : "NULL");

		// Check if the result matches the expected value
		if ((result == NULL && tests[i].expected_result == NULL) ||
			(result != NULL && tests[i].expected_result != NULL &&
			ft_strncmp(result, tests[i].expected_result, ft_strlen(tests[i].expected_result)) == 0))
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