
#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
    void	*ptr;
    size_t	total_size;

    total_size = count * size;
    if (count != 0 && total_size / count != size)
        return (NULL);
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    ft_memset(ptr, 0, total_size);
    return (ptr);
}

/*## Function: ft_calloc
### Prototype:
 `void	*ft_calloc(size_t count, size_t size)`

### Description:
 The `ft_calloc` function allocates memory for an array of `count` elements, each 
 of size `size`. The allocated memory is initialized to zero using `memset`. This 
 ensures that the allocated memory block is ready for use without containing any 
 garbage values. The function returns a pointer to the allocated and initialized 
 memory or `NULL` if the allocation fails or if there is an overflow in calculating 
 the total size.

### Parameters:
 - `size_t count`: The number of elements to allocate.
 - `size_t size`: The size of each element in bytes.

### Return:
 - Returns a pointer to the allocated memory initialized to zero.
 - If the allocation fails or if there is an overflow, the function returns `NULL`.

### Details:
 - The function first calculates the total size to be allocated by multiplying 
 `count` and `size`. It checks for overflow by verifying that the result of 
 `count * size` divided by `count` equals `size`. If the multiplication 
 overflows, the function returns `NULL`.
 - Memory is allocated using `malloc`. If the allocation fails, `NULL` is returned.
 - The allocated memory is then set to zero using `memset`, which ensures all bytes 
 in the allocated block are initialized to zero.
 - The function returns a pointer to the zero-initialized memory, ready to be used.

### Important notes:
 - The function returns `NULL` if the allocation fails or if there is an integer 
 overflow when calculating the total memory size (`count * size`).
 - The caller is responsible for freeing the allocated memory after use to avoid 
 memory leaks.*/
