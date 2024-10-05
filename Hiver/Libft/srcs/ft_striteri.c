
#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*## Function: ft_striteri
### Prototype:
 `void	ft_striteri(char *s, void (*f)(unsigned int, char*))`

### Description:
 The `ft_striteri` function applies the function `f` to each character of the 
 string `s`. The function `f` takes the index of the character as the first 
 argument and a pointer to the character as the second argument, allowing 
 modification of the characters in place.

### Parameters:
 - `char *s`: The string to iterate over.
 - `void (*f)(unsigned int, char*)`: A pointer to the function that is applied to 
 each character of the string. This function takes two parameters: an unsigned 
 integer (the index of the character) and a pointer to the character itself.

### Return:
 - None: This function does not return a value.

### Details:
 - The function iterates over the string `s`, passing the index and the address 
 of each character to the function `f` for modification.
 - The string `s` is modified in place.

### Important notes:
 - The function assumes that the string `s` is null-terminated.
 - If `s` or `f` is `NULL`, the function does nothing.*/
 // ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_striteri.c -L lib -lft -o test/test_ft_striteri

// ### Examples of usage:
#include <libft.h>
#include <stdio.h>

// Prototype of ft_striteri
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Prototypes of helper functions
int		ft_toupper(int c);

// Function to convert characters to uppercase with an index
void	to_uppercase(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

// Function to replace every second character with an A, every third character with a B.
void	alternate_with_A_B(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = 'A';  // Every 2nd character becomes 'A'
    else if (i % 3 == 0)
        *c = 'B';  // Every 3rd character becomes 'B'
}

// Function to increment each character by its index value
void	increment_by_index(unsigned int i, char *c)
{
	*c = *c + i;
}

// Function to print each character and its corresponding index
void	print_char_with_index(unsigned int i, char *c)
{
    printf("        Character at index %d: %c\n", i, *c);
}

// Main function to run the tests
int	main(void)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "HELLO, WORLD!";
	char	str3[] = "abcdef";

	printf("\n\033[4mTesting ft_striteri :\033[0m\n\n");

	// Test 1: Convert to uppercase using ft_toupper
	printf("\033[4mTest 1:\033[0m Convert to uppercase using ft_toupper\n");
	printf("        Before: %s\n", str1);
	ft_striteri(str1, to_uppercase);
	printf("        After:  %s\n\n", str1);

	// Test 2: Replace every second character with an A, every third character with a B.
	printf("\033[4mTest 2:\033[0m Replace every second character with an A, every third character with a B.\n");
	printf("        Before: %s\n", str2);
	ft_striteri(str2, alternate_with_A_B);
	printf("        After:  %s\n\n", str2);

	// Test 3: Increment each character by its index
	printf("\033[4mTest 3:\033[0m Increment each character by its index\n");
	printf("        Before: %s\n", str3);
	ft_striteri(str3, increment_by_index);
	printf("        After:  %s\n\n", str3);

	// Test 4: Print each character and its corresponding index
	printf("\033[4mTest 4:\033[0m Print each character and its corresponding index\n");
	ft_striteri(str3, print_char_with_index);
	printf("\n");

	return (0);
}