
#include <libft.h>

void	*ft_memchr(const void *buf, int c, size_t count)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*## Function: ft_memchr
### Prototype:
 `void	*ft_memchr(const void *buf, int c, size_t count)`

### Description:
 The `ft_memchr` function searches the first `count` bytes of the memory area pointed 
 to by `buf` for the first occurrence of the byte value `c` (converted to `unsigned char`). 
 The search stops once the byte `c` is found or when `count` bytes have been checked.

### Parameters:
 - `const void *buf`: A pointer to the memory area to be searched.
 - `int c`: The byte value to search for. This value is passed as an `int`, but 
 it is converted to an `unsigned char`.
 - `size_t count`: The number of bytes to search.

### Return:
 - Returns a pointer to the first occurrence of the byte `c` in the memory area 
 `buf`, or `NULL` if the byte is not found within the first `count` bytes.

### Details:
 - The function treats the memory as a sequence of `unsigned char` values, 
 comparing each byte in the memory area to the byte `c`.
 - If the byte is found, the function returns a pointer to the location of the 
 first occurrence of `c` in the memory area.
 - If `c` is not found in the first `count` bytes, the function returns `NULL`.

### Important notes:
 - The value `c` is converted to `unsigned char` for comparison, ensuring that 
 all possible byte values are handled correctly.*/
