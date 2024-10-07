
#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*## Function: ft_strlcpy
### Prototype:
 `size_t ft_strlcpy(char *dest, const char *src, size_t size)`

### Description:
 The `ft_strlcpy` function copies up to `size - 1` characters from the string 
 `src` to `dest`, ensuring that the result is null-terminated if `size` is greater 
 than 0. It mimics the behavior of the standard `strlcpy`, providing a safer 
 alternative to `strcpy`.

### Parameters:
 - `char *dest`: A pointer to the destination buffer where `src` will be copied.
 - `const char *src`: A pointer to the source string to be copied to `dest`.
 - `size_t size`: The size of the destination buffer, including space for the null 
 terminator.

### Return:
 - Returns the total length of the source string `src`.
 - If `size` is greater than the length of `src`, the entire string is copied.
 - If `size` is smaller, only `size - 1` characters are copied, and `dest` is 
 null-terminated.

### Details:
 - The function starts by checking if either `dest` or `src` is `NULL`. If so, 
 it returns `0`.
 - If `size > 0`, the function copies characters from `src` to `dest` until either 
 `size - 1` characters are copied or the null terminator in `src` is encountered.
 - After copying, `dest` is null-terminated to ensure a valid C-string.
 - The function continues counting the length of `src` even after reaching the 
 copy limit, to return the full length of `src`.

### Important notes:
 - The function does not allocate new memory. The caller must ensure that `dest` 
 has enough space to hold the result.
 - If `size` is 0, `dest` is not modified, but the length of `src` is still 
 returned.
 - This function ensures safe copying and avoids buffer overflows, as long as 
 `size` is properly set.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strlcpy.c -L lib -lft -o test/test_ft_strlcpy

// ### Examples of usage:
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strlcpy
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

