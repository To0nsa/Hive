
#include <libft.h>

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
    while (str[len] != '\0')
        len++;
    return (len);
}

/*## Function: ft_strlen
### Prototype:
 `size_t	ft_strlen(const char *str)`

### Description:
 The `ft_strlen` function calculates the length of the string pointed to by
 `str`, excluding the null terminator (`\0`). It iterates through each 
 character in the string until the null terminator is encountered.

### Parameters:
 - `const char *str`: A pointer to the string whose length is to be measured.

### Return:
 - Returns the number of characters in the string `str`, not including the null terminator.
 - If `str` is `NULL`, the function returns `0`.

### Details:
 - The function initializes a variable `len` to store the length of the string.
 - It first checks if `str` is `NULL`. If so, it immediately returns `0` to 
 handle invalid input safely.
 - The function then enters a loop where it iterates through each character of
 `str`, counting the number of characters until the null terminator (`\0`) is encountered.
 - Once the null terminator is reached, the function returns the value of `len`,
 representing the total number of characters in the string.

### Important notes:
 - The null-terminator (`\0`) is not included in the returned length. The function only
 counts actual characters in the string.
 - Always ensure that the input string is valid and null-terminated before passing
 it to `ft_strlen` to avoid undefined behavior.*/

// Compile with:
// cc -Wall -Wextra -Werror -I include srcs/ft_strlen.c -L lib -lft -o test/test_ft_strlen

// ### Examples of usage:
/* #include <libft.h>  // Ensure your libft header is included
#include <stdio.h>

// Prototype of ft_strlen
size_t	ft_strlen(const char *str);

// Define a struct to hold test case information
typedef struct	s_test_case
{
	const char	*str;
	size_t		expected;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Define test cases using the struct
	t_test_case tests[] = {
		{"Hello, World!", 13, "Normal string with letters, comma, and space"},
		{"", 0, "Empty string"},
		{"\n", 1, "String with newline character"},
		{"1234567890", 10, "String with numeric characters"},
		{"abcdef", 6, "Simple alphabetic string"},
		{"\0HiddenText", 0, "String starting with null terminator"},
		{"This is a long string that tests a longer sequence of characters.", 65, "Long string with spaces and punctuation"}
	};
	int	num_tests = 7;
	int	i = 0;

	// Iterate through test cases using a while loop
	while (i < num_tests)
	{
		size_t result = ft_strlen(tests[i].str);

		printf("\n\033[4mTesting ft_strlen :\033[0m\n\n");

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("String: \"%s\"\n", tests[i].str);
		printf("Expected Length: %zu\n", tests[i].expected);
		printf("Actual Length: %zu\n", result);

		// Check if the result matches the expected value
		if (result == tests[i].expected)
			printf("Result: \033[32mPASS\033[0m - %s\n", tests[i].description);
		else
			printf("Result: \033[31mFAIL\033[0m - %s\n", tests[i].description);
		printf("---------------------------\n");
		i++;
	}
	return 0;
} */
