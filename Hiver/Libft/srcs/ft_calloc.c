
#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
    void	*ptr;
    size_t	total_size;

    total_size = nmemb * size;
    if (nmemb != 0 && total_size / nmemb != size)
        return (NULL);
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    ft_memset(ptr, 0, total_size);
    return (ptr);
}

/*## Function: ft_calloc
### Prototype:
 `void	*ft_calloc(size_t nmemb, size_t size)`

### Description:
 The `ft_calloc` function allocates memory for an array of `nmemb` elements, each 
 of size `size`. The allocated memory is initialized to zero using `memset`. This 
 ensures that the allocated memory block is ready for use without containing any 
 garbage values. The function returns a pointer to the allocated and initialized 
 memory or `NULL` if the allocation fails or if there is an overflow in calculating 
 the total size.

### Parameters:
 - `size_t nmemb`: The number of elements to allocate.
 - `size_t size`: The size of each element in bytes.

### Return:
 - Returns a pointer to the allocated memory initialized to zero.
 - If the allocation fails or if there is an overflow, the function returns `NULL`.

### Details:
 - The function first calculates the total size to be allocated by multiplying 
 `nmemb` and `size`. It checks for overflow by verifying that the result of 
 `nmemb * size` divided by `nmemb` equals `size`. If the multiplication 
 overflows, the function returns `NULL`.
 - Memory is allocated using `malloc`. If the allocation fails, `NULL` is returned.
 - The allocated memory is then set to zero using `memset`, which ensures all bytes 
 in the allocated block are initialized to zero.
 - The function returns a pointer to the zero-initialized memory, ready to be used.

### Important notes:
 - The function returns `NULL` if the allocation fails or if there is an integer 
 overflow when calculating the total memory size (`nmemb * size`).
 - The caller is responsible for freeing the allocated memory after use to avoid 
 memory leaks.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_calloc.c -L lib -lft -o test/test_ft_calloc

//### Examples of usage:
#include <stdio.h>		// For printf
#include <stdint.h>		// For SIZE_MAX

// Helper function to verify if memory is zeroed
int	ft_is_memzeroed(void *ptr, size_t n)
{
	unsigned char	*byte_ptr = (unsigned char *)ptr;
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (byte_ptr[i] != 0)
			return (0);	// Not zeroed
		i++;
	}
	return (1);	// All bytes are zeroed
}

// Helper function to print test results
void	ft_print_test_result(const char *test_name, int passed)
{
	if (passed)
		printf("[PASS] %s\n", test_name);
	else
		printf("[FAIL] %s\n", test_name);
}

int	main(void)
{
	// Test Case 1: Typical Allocation
	{
		size_t	nmemb = 10;
		size_t	size = sizeof(int);
		int		*arr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (arr != NULL && ft_is_memzeroed(arr, nmemb * size))
			passed = 1;
		ft_print_test_result("Typical Allocation (10 integers)", passed);
		free(arr);
	}

	// Test Case 2: Zero Allocation (nmemb = 0)
	{
		size_t	nmemb = 0;
		size_t	size = sizeof(int);
		int		*arr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (arr == NULL || ft_is_memzeroed(arr, 0))
			passed = 1;
		ft_print_test_result("Zero Allocation (nmemb = 0)", passed);
		free(arr);	// Safe to call free on NULL in C
	}

	// Test Case 3: Zero Allocation (size = 0)
	{
		size_t	nmemb = 10;
		size_t	size = 0;
		int		*arr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (arr == NULL || ft_is_memzeroed(arr, 0))
			passed = 1;
		ft_print_test_result("Zero Allocation (size = 0)", passed);
		free(arr);	// Safe to call free on NULL in C
	}

	// Test Case 4: Both nmemb and size are zero
	{
		size_t	nmemb = 0;
		size_t	size = 0;
		int		*arr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (arr == NULL || ft_is_memzeroed(arr, 0))
			passed = 1;
		ft_print_test_result("Zero Allocation (nmemb = 0, size = 0)", passed);
		free(arr);	// Safe to call free on NULL in C
	}

	// Test Case 5: Overflow Detection
	{
		size_t	nmemb = SIZE_MAX;
		size_t	size = 2;
		void	*ptr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (ptr == NULL)
			passed = 1;
		ft_print_test_result("Overflow Detection (SIZE_MAX * 2)", passed);
		free(ptr);
	}

	// Test Case 6: Large Allocation (may vary based on system)
	{
		size_t	nmemb = 1000000;
		size_t	size = sizeof(int);
		int		*arr = ft_calloc(nmemb, size);
		int		passed = 0;

		if (arr != NULL && ft_is_memzeroed(arr, nmemb * size))
			passed = 1;
		ft_print_test_result("Large Allocation (1,000,000 integers)", passed);
		free(arr);
	}

	// Test Case 7: Allocation of Structs
	{
		typedef struct	s_point
		{
			int	x;
			int	y;
		}				t_point;

		size_t	nmemb = 5;
		size_t	size = sizeof(t_point);
		t_point	*points = ft_calloc(nmemb, size);
		int		passed = 0;

		if (points != NULL && ft_is_memzeroed(points, nmemb * size))
			passed = 1;
		ft_print_test_result("Allocation of Structs (5 points)", passed);
		free(points);
	}

	// Test Case 8: Multiple Allocations in a Loop
	{
		size_t	i;
		size_t	loops = 1000;
		int		*arr;
		int		passed = 1;

		for (i = 0; i < loops; i++)
		{
			arr = ft_calloc(100, sizeof(int));
			if (arr == NULL || !ft_is_memzeroed(arr, 100 * sizeof(int)))
			{
				passed = 0;
				break;
			}
			free(arr);
		}
		ft_print_test_result("Multiple Allocations in a Loop (1000 iterations)", passed);
	}

	// Test Case 9: Allocation of Different Data Types
	{
		typedef struct	s_data
		{
			double	a;
			char	b;
			long	c;
		}				t_data;

		size_t	nmemb = 3;
		size_t	size = sizeof(t_data);
		t_data	*data = ft_calloc(nmemb, size);
		int		passed = 0;

		if (data != NULL && ft_is_memzeroed(data, nmemb * size))
			passed = 1;
		ft_print_test_result("Allocation of Different Data Types (3 data structs)", passed);
		free(data);
	}

	// Test Case 10: Allocation with Maximum Size that Doesn't Overflow
	{
		size_t	nmemb = SIZE_MAX / 2;
		size_t	size = 2;
		void	*ptr = ft_calloc(nmemb, size);
		int		passed = 0;

		// This may or may not fail depending on system memory
		if (ptr == NULL || ft_is_memzeroed(ptr, nmemb * size))
			passed = 1;
		ft_print_test_result("Maximum Allocation without Overflow (SIZE_MAX/2 * 2)", passed);
		free(ptr);
	}

	return (0);
}