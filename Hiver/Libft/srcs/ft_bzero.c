
#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*## Function: ft_bzero
### Prototype:
 `void	ft_bzero(void *s, size_t n)`

### Description:
 The `ft_bzero` function sets the first `n` bytes of the memory area pointed to 
 by `s` to zero. It is commonly used to initialize blocks of memory to all zeroes, 
 ensuring that all data in the specified memory range is cleared.

### Parameters:
 - `void *s`: A pointer to the memory area that will be set to zero.
 - `size_t n`: The number of bytes to set to zero.

### Return:
 - None: This function does not return a value.

### Details:
 - The function casts the memory area pointer `s` to `unsigned char *` to handle 
 the memory byte by byte.
 - It then iterates through the first `n` bytes of the memory area and sets each 
 byte to `0`.
 - This function is typically used to zero out blocks of memory before using them 
 in subsequent operations.

### Important notes:
 - The function does not return any value since it modifies the memory directly.
 - This function is equivalent to `ft_memset(s, 0, n)` but is specialized for 
 setting memory to zero.*/
 