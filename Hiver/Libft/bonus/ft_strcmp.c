
#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
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

/*## Function: ft_strcmp
### Prototype:
 `int	ft_strcmp(const char *s1, const char *s2)`

### Description:
 The `ft_strcmp` function compares the null-terminated strings `s1` and `s2`. It
 performs a lexicographical comparison and returns an integer less than, equal to,
 or greater than zero, depending on whether `s1` is found to be less than, equal
 to, or greater than `s2`.

### Parameters:
 - `const char *s1`: The first string to be compared.
 - `const char *s2`: The second string to be compared.

### Return:
 - Returns an integer less than zero if `s1` is less than `s2`.
 - Returns zero if `s1` is equal to `s2`.
 - Returns an integer greater than zero if `s1` is greater than `s2`.

### Details:
 - The function iterates through both strings, comparing characters one by one
 until a difference is found or a null terminator is encountered.
 - Characters are compared using their `unsigned char` values to handle extended
 ASCII characters correctly.
 - If a difference is found, the function returns the difference between the first
 two differing characters.
- If the strings are identical, the function returns `0`.*/
