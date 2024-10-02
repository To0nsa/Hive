
#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < s + count)
	{
		while (count--)
			d[count] = s[count];
	}
	else
	{
		while (count--)
			*d++ = *s++;
	}
	return (dest);
}

/*## Function: ft_memmove
### Prototype:
 `void	*ft_memmove(void *dest, const void *src, size_t count)`

### Description:
 The `ft_memmove` function copies `count` bytes from the memory area `src` to the 
 memory area `dest`. It safely handles overlapping memory regions by ensuring 
 that the copy is done in a way that prevents data corruption. The function returns 
 a pointer to the destination memory area `dest`.

### Parameters:
 - `void *dest`: A pointer to the destination memory area where the data will be 
 copied.
 - `const void *src`: A pointer to the source memory area to copy the data from.
 - `size_t count`: The number of bytes to copy from `src` to `dest`.

### Return:
 - Returns a pointer to the destination memory area `dest`.

### Details:
 - The function first checks if `src` and `dest` are overlapping and copies the 
 memory in reverse order if necessary to avoid overwriting data.
 - If `src` and `dest` do not overlap or if `dest` is before `src`, the copy is 
 done normally from the beginning of the memory block.
 - It handles copying byte by byte, converting the pointers to `unsigned char *`.

### Important notes:
 - This function handles overlapping memory areas properly, unlike `memcpy`, 
 which assumes that the memory areas do not overlap.*/