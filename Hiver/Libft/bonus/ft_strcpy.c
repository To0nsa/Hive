
#include <libft.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*## Function: `ft_strcpy`
### Prototype:
 `char	*ft_strcpy(char *dest, const char *src)`

### Description:
 The `ft_strcpy` function copies the string pointed to by `src` (including
 the null terminator `'\0'`) to the buffer pointed to by `dest`. The destination
 buffer **must be large enough** to hold the content of the source string, 
 including the null-terminating character.

### Parameters:
 - `char *dest`: A pointer to the destination buffer where the string will be copied to.
 - `const char *src`: A pointer to the source string that will be copied to the destination.

### Return:
 - Returns the pointer to the destination string dest after the copying is done.

### Details:
 - A loop iterates through each character of the source string (`src`), copying each
 character one-by-one to the destination string (`dest`).
 - The loop continues until the null-terminator character (`'\0'`) is encountered in `src`,
 signaling the end of the string.
 - Once the copying is complete, a null-terminator (`'\0'`) is explicitly added to the 
 end of the `dest` string to ensure it is properly terminated.
 - Finally, the function returns the `dest` pointer, allowing it to be used 
 directly or chained in operations.
 
### Important notes:
 - The caller must ensure that the destination buffer (`dest`) is large enough to hold
 the source string, including the null-terminator. Otherwise, this could result in 
 buffer overflow or undefined behavior.
 - The function only works for null-terminated strings.*/
