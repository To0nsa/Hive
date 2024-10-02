
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