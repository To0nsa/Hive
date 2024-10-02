
#include <libft.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*## Function: `ft_strchr`
### Prototype:
 `char	*ft_strchr(const char *str, int c)`

### Description:
 The `ft_strchr` function searches for the first occurrence of the character `c`
 in the string pointed to by `str`. It scans through the string, including the 
 null terminator `\0`.

### Parameters:
 - `const char *str`: A pointer to the string in which the search will be performed.
 - `int c`: The character to search for, passed as an `int` but internally cast to `char`.

### Return:
 - Returns a pointer to the first occurrence of the character `c` in the string `str`.
 - If `c` is not found, the function returns `NULL`.
 - If `c` is the null terminator (`\0`), the function returns a pointer to
 the null terminator in `str`.

### Details:
 - The function begins by iterating through the string `str` one character at a time.
 - For each character, it checks if the current character matches the given `c` 
 (converted to `char`).
 - If a match is found, the function immediately returns a pointer to that character
 within the string.
 - If no match is found by the end of the string and `c` is the null terminator, 
 it returns a pointer to the null terminator at the end of the string.
 - If the character `c` is not found in the string (and it's not the null terminator),
 the function returns `NULL`.

### Important notes:
 - The search includes the null-terminator character `\0`, meaning if `c` is `\0`, 
 the function will return a pointer to the null terminator in `str`.
 - If `c` is not found in the string, the returned `NULL` should be handled to avoid
 dereferencing null pointers.
 - Since `c` is passed as an `int`, it is cast to `char` internally for comparison 
 with the characters in the string.
*/