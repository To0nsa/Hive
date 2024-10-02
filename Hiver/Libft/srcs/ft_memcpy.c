
#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*## Function: ft_memcpy
### Prototype:
 `void	*ft_memcpy(void *dest, const void *src, size_t count)`

### Description:
 The `ft_memcpy` function copies `count` bytes from the memory area `src` to the 
 memory area `dest`. The memory areas must not overlap, as the behavior is 
 undefined in such cases. The function returns a pointer to the destination 
 memory `dest`.

### Parameters:
 - `void *dest`: A pointer to the destination memory area where the data will be 
 copied.
 - `const void *src`: A pointer to the source memory area to copy the data from.
 - `size_t count`: The number of bytes to copy from `src` to `dest`.

### Return:
 - Returns a pointer to the destination memory area `dest`.

### Details:
 - The function casts both `src` and `dest` to `unsigned char *` to handle the 
 copy operation byte by byte.
 - It then iterates over the first `count` bytes of the source memory and copies 
 each byte to the destination memory.
 - The function does not handle overlapping memory areas. For overlapping memory, 
 `memmove` should be used instead.

### Important notes:
 - The source and destination memory areas must not overlap, as this can cause 
 undefined behavior.*/
