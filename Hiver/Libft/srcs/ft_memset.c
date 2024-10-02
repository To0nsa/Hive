
#include <libft.h>

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

/*## Function: ft_memset
### Prototype:
 `void	*ft_memset(void *b, int c, size_t len)`

### Description:
 The `ft_memset` function fills the first `count` bytes of the memory area pointed 
 to by `dest` with the constant byte `c`. It returns a pointer to the memory area 
 `dest`. This function is used to set a block of memory to a specific value.

### Parameters:
 - `void *dest`: A pointer to the memory area to be filled.
 - `int c`: The byte value to be set. This value is passed as an `int`, but it 
 is converted to an unsigned char internally.
 - `size_t count`: The number of bytes to set to the value of `c`.

### Return:
 - Returns a pointer to the memory area `dest`.

### Details:
 - The function first casts the pointer `dest` to a `unsigned char *` because 
 memory is treated byte by byte.
 - It then iterates over the memory area, setting each byte to the value `c` 
 until `count` bytes are processed.
 - The function returns the pointer to the original memory block `dest`.

### Important notes:
 - The value `c` is internally treated as an unsigned char, so any integer 
 passed will be converted to an 8-bit value.*/