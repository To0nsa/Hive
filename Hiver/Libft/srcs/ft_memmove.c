
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

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_memmove.c -L lib -lft -o test/test_ft_memmove

// ### Examples of usage:
/* #include "libft.h"
#include <stdio.h>
#include <string.h>  // For memmove

// Prototype of ft_memmove
void	*ft_memmove(void *dest, const void *src, size_t count);

// Prototype of helper functions
void	ft_memprint_hex(const void *s, size_t n);
void	*ft_memset(void *dest, int c, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);

void	ft_memprint_hex(const void *s, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	size_t				i;
	const char			*hex_digits = "0123456789abcdef";
	char				output[3];

	output[2] = ' ';
	i = 0;
	while (i < n)
	{
		output[0] = hex_digits[ptr[i] / 16];
		output[1] = hex_digits[ptr[i] % 16];
		write(1, output, 3);
		i++;
	}
	write(1, "\n", 1);
}

int main(void)
{
	typedef struct s_test_case
	{
		const char 	*description;
		size_t		buffer_size;
		size_t		dest_offset;
		size_t		src_offset;
		size_t 		n;
	}				t_test_case;

	// Define test cases
	t_test_case tests[] = {
		{"Test 1: Non-overlapping regions (dest before src)", 20, 0, 10, 10},
		{"Test 2: Non-overlapping regions (src before dest)", 20, 10, 0, 10},
		{"Test 3: Overlapping regions (dest starts within src)", 20, 5, 0, 15},
		{"Test 4: Overlapping regions (src starts within dest)", 20, 0, 5, 15},
		{"Test 5: dest and src are the same", 20, 0, 0, 20},
		{"Test 6: n = 0 (no operation)", 20, 5, 10, 0},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int i = 0;

	printf("\033[4mTesting ft_memmove:\033[0m\n\n");

	while (i < num_tests)
	{
		unsigned char buffer[100];
		unsigned char buffer_ft[100];
		unsigned char buffer_std[100];
		unsigned char *dest_ft = NULL;
		unsigned char *dest_std = NULL;
		unsigned char *src_ft = NULL;
		unsigned char *src_std = NULL;
		size_t j;

		printf("%s\n", tests[i].description);

		// Initialize the buffer with known values using ft_memset
		ft_memset(buffer, 'A', sizeof(buffer));

		// Modify buffer values for testing
		j = 0;
		while (j < tests[i].buffer_size)
		{
			buffer[j] = 'A' + (j % 26);
			j++;
		}

		// Copy buffer to buffer_ft and buffer_std
		ft_memcpy(buffer_ft, buffer, sizeof(buffer));
		ft_memcpy(buffer_std, buffer, sizeof(buffer));

		// Set up source and destination pointers with offsets
		dest_ft = buffer_ft + tests[i].dest_offset;
		dest_std = buffer_std + tests[i].dest_offset;
		src_ft = buffer_ft + tests[i].src_offset;
		src_std = buffer_std + tests[i].src_offset;

		// Apply ft_memmove
		ft_memmove(dest_ft, src_ft, tests[i].n);

		// Apply standard memmove
		memmove(dest_std, src_std, tests[i].n);

		// Compare the results
		int result = ft_memcmp(buffer_ft, buffer_std, tests[i].buffer_size);

		// Print initial buffer state (after initialization and before memmove)
		printf("Initial buffer state:     ");
		fflush(stdout);
		ft_memprint_hex(buffer, tests[i].buffer_size);

		// Print buffer after memmove
		printf("Buffer after memmove:     ");
		fflush(stdout);
		ft_memprint_hex(buffer_std, tests[i].buffer_size);

		// Print buffer after ft_memmove
		printf("Buffer after ft_memmove:  ");
		fflush(stdout);
		ft_memprint_hex(buffer_ft, tests[i].buffer_size);

		// Check if results are the same
		if (result == 0)
			printf("Status \033[32mPASS\033[0m\n");
		else
			printf("Status \033[31mFAIL\033[0m\n");

		printf("---------------------------\n");
		i++;
	}
	return (EXIT_SUCCESS);
} */