
#include <libft.h>

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)buf1;
	ptr2 = (const unsigned char *)buf2;
	i = 0;
	while (i < count)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*## Function: ft_memcmp
### Prototype:
 `int	ft_memcmp(const void *buf1, const void *buf2, size_t count)`

### Description:
 The `ft_memcmp` function compares the first `count` bytes of the memory areas 
 `buf1` and `buf2`. The comparison is done byte by byte, and it returns an integer 
 indicating whether the first difference between the memory blocks makes `buf1` 
 less than, equal to, or greater than `buf2`.

### Parameters:
 - `const void *buf1`: A pointer to the first memory area.
 - `const void *buf2`: A pointer to the second memory area.
 - `size_t count`: The number of bytes to compare.

### Return:
 - Returns an integer less than 0 if `buf1` is less than `buf2`.
 - Returns 0 if `buf1` is equal to `buf2`.
 - Returns an integer greater than 0 if `buf1` is greater than `buf2`.

### Details:
 - The function treats the memory as a sequence of `unsigned char` values, 
 comparing each byte in `buf1` to the corresponding byte in `buf2`.
 - If a difference is found, the function immediately returns the difference 
 between the two differing bytes.
 - If no difference is found within `count` bytes, the function returns 0.

### Important notes:
 - The function stops comparing as soon as it finds a difference, even if fewer 
 than `count` bytes have been checked.
 - The memory areas `buf1` and `buf2` are treated as sequences of `unsigned char` 
 to ensure correct comparison for all byte values.*/