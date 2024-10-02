
#include <libft.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*## Function: `ft_strncpy`
### Prototype:
 `char	*ft_strncpy(char *dest, const char *src, size_t n)`

### Description:
 The `ft_strncpy` function copies up to `n` characters from the string pointed to
 by `src` to the buffer pointed to by `dest`. If the source string is shorter than `n`,
 the remaining characters in dest are filled with null characters (`'\0'`).

### Parameters:
 - `char *dest`: A pointer to the destination buffer where the string will be copied to.
 - `const char *src`: A pointer to the source string to be copied.
 - `size_t n`: The maximum number of characters to copy.

### Return:
 - Returns the pointer to the destination string `dest` after copying.

### Details:
 - A loop iterates through each character of the source string (`src`), 
 copying up to `n` characters to the destination string (`dest`).
 - If `src` contains fewer than `n` characters, the remaining part of `dest`
 will be padded with null characters (`'\0'`) until `n` characters are filled.
 - The function does not append a null terminator automatically if `n` characters
 are copied and no null terminator is found in the source string.
 - Finally, the function returns the `dest` pointer.
 
 ### Important notes:
 - The destination buffer (`dest`) must be large enough to hold at least `n` characters.
 - Unlike `ft_strcpy`, this function will not guarantee that the resulting string 
 is null-terminated if `n` characters are copied without encountering the null terminator
 in src.*/