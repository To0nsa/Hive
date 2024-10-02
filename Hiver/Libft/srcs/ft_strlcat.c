
#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = 0;
	src_len = 0;
	if (!dest || !src)
    	return (0);
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*## Function: ft_strlcat
### Prototype:
 `size_t ft_strlcat(char *dest, const char *src, size_t size)`

### Description:
 The `ft_strlcat` function appends the string `src` to the end of `dest`, up to 
 a total size of `size` bytes. It ensures that the resulting string in `dest` is 
 null-terminated. The function operates similarly to `strncat` but guarantees 
 that the total length of the concatenated string will not exceed `size`.

### Parameters:
 - `char *dest`: A pointer to the destination string where `src` will be appended.
 - `const char *src`: A pointer to the source string to be appended to `dest`.
 - `size_t size`: The total size of the destination buffer, including space for 
 the null terminator.

### Return:
 - Returns the total length of the string that would have been created if `size` 
 was large enough (i.e., the length of `dest` plus the length of `src`).
 - If the size is smaller than the length of `dest`, the function returns `size` 
 plus the length of `src`.

### Details:
 - The function first calculates the length of `dest` up to a maximum of `size`. 
 If the length of `dest` equals `size`, the function returns `size + src_len`.
 - It then calculates the length of `src`.
 - The function appends `src` to `dest` while ensuring that the total length does 
 not exceed `size - 1` to leave room for the null terminator.
 - The destination string is guaranteed to be null-terminated, as long as `size` 
 is greater than 0.

### Important notes:
 - The function does not allocate new memory; the caller must ensure that `dest` 
 has enough space to hold the result.
 - If `size` is 0, the function returns the length of `src`.
 - This function mimics the behavior of the standard `strlcat`, ensuring safe 
 concatenation and preventing buffer overflows.*/
 