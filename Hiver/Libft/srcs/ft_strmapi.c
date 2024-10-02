
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t 	len;
	size_t 	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*## Function: ft_strmapi
### Prototype:
 `char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))`

### Description:
 The `ft_strmapi` function applies the function `f` to each character of the 
 string `s` to create a new string. The function `f` takes the index of the 
 character as its first argument and the character itself as the second argument.
 A new string is created with `malloc`, and each character is replaced by the 
 result of applying `f` to the corresponding character from `s`.

### Parameters:
 - `const char *s`: The string on which to iterate.
 - `char (*f)(unsigned int, char)`: A pointer to the function that is applied to 
 each character of the string. This function takes two parameters: an unsigned 
 integer (the index of the character) and the character itself.

### Return:
 - Returns a new string created by applying `f` to each character of `s`.
 - Returns `NULL` if memory allocation fails.

### Details:
 - The function first calculates the length of the string `s`.
 - Memory is allocated for the new string, which will have the same length as `s`.
 - The function iterates over the string `s`, applies the function `f` to each 
 character, and stores the result in the newly allocated string.
 - The function returns the newly created string, which is null-terminated.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the new string.
 - If `s` or `f` is `NULL`, the function returns `NULL`.*/