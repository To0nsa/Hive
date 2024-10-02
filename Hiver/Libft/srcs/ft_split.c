
#include <libft.h>

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*str)
	{
		if (*str != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*str == c)
			in_substring = 0;
		str++;
	}
	return (count);
}

static int	ft_word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_free_array(char **array, int nb_words)
{
	int	i;

	i = 0;
	while (i < nb_words)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(const char *str, char c)
{
	char	**array;
	int		nb_words;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	nb_words = ft_word_count(str, c);
	array = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		while (*str && *str == c)
			str++;
		len = ft_word_len(str, c);
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[i])
		{
			ft_free_array(array, i);
			return (NULL);
		}
		ft_strncpy(array[i], str, len);
		str += len;
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
 `static char		*ft_strncpy(char *dest, const char *src, int n)`
 `static void		ft_free_array(char **array, int nb_words)`

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
 - The function allocates memory for the array of strings (`nb_words + 1`) where 
 `nb_words` is the number of words found in `str`.
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
