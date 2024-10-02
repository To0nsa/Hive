
#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}

/*## Function: ft_strncmp
### Prototype:
 `int	ft_strncmp(const char *s1, const char *s2, size_t n)`

### Description:
 The `ft_strncmp` function compares up to `n` characters of the strings `s1` and
 `s2`. It performs a lexicographical comparison and returns an integer less than,
 equal to, or greater than zero, depending on whether `s1` is found to be less
 than, equal to, or greater than `s2`.

### Parameters:
 - `const char *s1`: The first string to be compared.
 - `const char *s2`: The second string to be compared.
 - `size_t n`: The maximum number of characters to compare.

### Return:
 - Returns an integer less than zero if `s1` is less than `s2`.
 - Returns zero if `s1` is equal to `s2`.
 - Returns an integer greater than zero if `s1` is greater than `s2`.

### Details:
 - The comparison is performed using unsigned characters to ensure that characters
 with values greater than 127 are handled correctly.
 - The function iterates through both strings, comparing characters one by one up
 to `n` characters or until a null terminator is encountered.
 - If a difference is found between the characters, the function returns the
 difference between the first two differing characters.
 - If the strings are equal for the first `n` characters, the function returns `0`.*/
