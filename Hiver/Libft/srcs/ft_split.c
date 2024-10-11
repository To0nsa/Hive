
#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

static size_t	ft_word_count(const char *str, char c)
{
	size_t	word_count;
	int		in_substring;

	word_count = 0;
	in_substring = 0;
	while (*str)
	{
		if (*str != c && in_substring == 0)
		{
			in_substring = 1;
			word_count++;
		}
		else if (*str == c)
			in_substring = 0;
		str++;
	}
	return (word_count);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	return (word_len);
}

static void	ft_free_array(char **array, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(const char *str, char c)
{
	char		**array;
	size_t		word_count;
	size_t		word_len;
	size_t		i;

	if (!str)
		return (NULL);
	word_count = ft_word_count(str, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str && *str == c)
			str++;
		word_len = ft_word_len(str, c);
		array[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!array[i])
		{
			ft_free_array(array, i);
			return (NULL);
		}
		ft_strlcpy(array[i], str, word_len);
		str += word_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*## Function: ft_split
### Prototype:
 `char			**ft_split(const char *str, char c)`

### Helper function prototypes:
 `static int		ft_word_count(const char *str, char c)`
 `static int		ft_word_len(const char *str, char c)`
 `static char		*ft_strlcpy(char *dest, const char *src, int n)`
 `static void		ft_free_array(char **array, int word_count)`

### Description:
 The `ft_split` function splits the string `str` into an array of words based on a 
 delimiter character `c`. Each word is separated by the character `c`, and the 
 function returns an array of null-terminated strings.

### Parameters:
 - `const char *str`: The input string to be split into words.
 - `char c`: The delimiter character that separates words in the input string.

### Return:
 - Returns a pointer to a dynamically allocated array of strings (words).
 - If memory allocation fails or if `str` is `NULL`, the function returns `NULL`.

### Details:
 - The function first checks if `str` is `NULL`. If so, it returns `NULL`.
 - The helper function `ft_word_count` is used to determine how many words are in 
 the string, based on the delimiter `c`.
 - The function allocates memory for the array of strings (`word_count + 1`) where 
 `word_count` is the number of words found in `str`.
 - It iterates through the string `str`, skipping over delimiters, and calculates 
 the length of each word using the helper `ft_word_len`.
 - For each word, memory is allocated, and `ft_strncpy` is used to copy the word 
 into the newly allocated space.
 - If memory allocation fails for any word, the helper function `ft_free_array` 
 is called to free all previously allocated memory.
 - The function terminates the array with a `NULL` pointer.

### Important notes:
 - The caller is responsible for freeing the array of strings and the strings 
 themselves to avoid memory leaks.
 - The function handles multiple consecutive delimiters by skipping them and 
 starting a new word at the next non-delimiter character.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_split.c -L lib -lft -o test/test_ft_split

// ### Examples of usage:
/* #include <libft.h>

// Prototype of ft_split
char	**ft_split(const char *str, char c);

// Prototypes of helper functions
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

// Function to free the result array after tests
void	free_result(char **result)
{
	int	i = 0;

	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

// Function to print the result of ft_split
void	print_split_result(char **result)
{
	int	i = 0;

	while (result[i])
	{
		ft_putchar_fd('0' + (i + 1), 1);
		ft_putchar_fd(':', 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd(result[i], 1);
		i++;
	}
}

// Test cases for ft_split
int	main(void)
{
	char **result;

	// Testing ft_split by writing results to stdout (fd 1)
	ft_putendl_fd("\n\033[4mTesting ft_split (writing to stdout):\033[0m\n", 1);

	// Test 1: Split a normal sentence
	ft_putendl_fd("\033[4mTest 1:\033[0m Split \"Hello world this is a test\" by space (' ')", 1);
	result = ft_split("Hello world this is a test", ' ');
	print_split_result(result);
	free_result(result);
	ft_putchar_fd('\n', 1);

	// Test 2: Split with multiple consecutive delimiters
	ft_putendl_fd("\033[4mTest 2:\033[0m Split \"Hello,,,world,,,test\" by comma (',')", 1);
	result = ft_split("Hello,,,world,,,test", ',');
	print_split_result(result);
	free_result(result);
	ft_putchar_fd('\n', 1);

	// Test 3: Split an empty string
	ft_putendl_fd("\033[4mTest 3:\033[0m Split an empty string \"\" by any character ('.')", 1);
	result = ft_split("", '.');
	print_split_result(result);
	free_result(result);
	ft_putchar_fd('\n', 1);

	// Test 4: Split with delimiter at the start and end
	ft_putendl_fd("\033[4mTest 4:\033[0m Split \"!!Hello!World!Test!\" by exclamation mark ('!')", 1);
	result = ft_split("!!Hello!World!Test!", '!');
	print_split_result(result);
	free_result(result);
	ft_putchar_fd('\n', 1);

	// Test 5: Split with no delimiter present
	ft_putendl_fd("\033[4mTest 5:\033[0m Split \"NoDelimiterHere\" by space (' ')", 1);
	result = ft_split("NoDelimiterHere", ' ');
	print_split_result(result);
	free_result(result);
	ft_putchar_fd('\n', 1);

	// Test 6: Split NULL input
	ft_putendl_fd("\033[4mTest 6:\033[0m Split NULL input", 1);
	result = ft_split(NULL, ' ');
	if (result == NULL)
		ft_putendl_fd("Result is NULL as expected", 1);
	ft_putchar_fd('\n', 1);

	return (0);
} */