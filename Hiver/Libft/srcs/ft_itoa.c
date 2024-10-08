
#include <libft.h>

static size_t	ft_n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t 	len;
	long	nb;

	nb = n;
	len = ft_n_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
		len;
	}
	return (str);
}

/*## Function: ft_itoa
### Prototype:
 `char	*ft_itoa(int n)`

### Description:
 The `ft_itoa` function converts an integer `n` into a null-terminated string 
 representation. It allocates memory dynamically for the string and handles both 
 positive and negative numbers. The function returns the string, or `NULL` if the 
 memory allocation fails.

### Parameters:
 - `int n`: The integer to convert into a string.

### Return:
 - Returns a pointer to the string representing the integer.
 - If memory allocation fails, the function returns `NULL`.

### Details:
 - The function first determines the number of digits in the integer (including 
 space for the negative sign if needed).
 - It allocates memory for the string, including the null terminator.
 - The function converts the integer to its string representation from the last 
 digit to the first, handling negative numbers by adding a minus sign.
 - It returns the allocated string.

### Important notes:
 - The caller is responsible for freeing the allocated memory to avoid memory 
 leaks.
 - If `n` is `0`, the function returns `"0"`.
 - The function handles the edge case for the minimum value of an integer (`INT_MIN`).*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_itoa.c -L lib -lft -o test/test_ft_itoa

// ### Examples of usage:
#include <stdio.h>
#include <limits.h>


// Structure to hold individual test cases
typedef struct	s_test_case
{
	int			input;
	const char	*expected_output;
	const char	*description;
}				t_test_case;

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}

int	main(void)
{
	// Define test cases for ft_itoa
	t_test_case tests[] = {
		{ 0, "0", "Zero" },
		{ 1, "1", "Positive Single Digit (1)" },
		{ -1, "-1", "Negative Single Digit (-1)" },
		{ 12345, "12345", "Positive Number (12345)" },
		{ -12345, "-12345", "Negative Number (-12345)" },
		{ INT_MAX, "2147483647", "INT_MAX" },
		{ INT_MIN, "-2147483648", "INT_MIN" },
		{ 100000, "100000", "Large Positive Number (100000)" },
		{ -999999, "-999999", "Large Negative Number (-999999)" },
	};

	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	char	*result;

	printf("Testing ft_itoa:\n");
	printf("---------------------------------------------------------------------------\n");
	printf("%-5s | %-11s | %-13s | %-13s | %s | %s\n", "Test", "Input", "Expected", "Output", "Result", "Description");
	printf("---------------------------------------------------------------------------\n");

	// Iterate through the test cases
	while (i < num_tests)
	{
		// Call ft_itoa with the current input
		result = ft_itoa(tests[i].input);
		printf("%-5zu | %-11d | %-13s | %-13s | ", i + 1, tests[i].input, tests[i].expected_output, result);

		// Determine PASS or FAIL
		if (ft_strcmp(result, tests[i].expected_output) == 0)
			printf("PASS");
		else
			printf("FAIL");

		// Print description
		printf("   | %s\n", tests[i].description);

		// Free the result allocated by ft_itoa
		free(result);
		i++;
	}
	printf("---------------------------------------------------------------------------\n");
	return (0);
}