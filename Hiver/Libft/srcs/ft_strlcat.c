
#include <libft.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	space_left;

	if (!dest || !src)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	space_left = size - dest_len;
	if (size <= dest_len)
		return (size + src_len);
	ft_strlcpy(dest + dest_len, src, space_left);
	return (total_len);
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

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_strlcat.c -L lib -lft -o test/test_ft_strlcat

// ### Examples of usage:
#include <libft.h>
#include <stdio.h>

// Prototype of ft_strlcat
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// Prototype of helper function
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

void	test_ft_strlcat(const char *initial_dest, const char *src, size_t size, int test_number)
{
	char dest[50];
	size_t result;

	// Initialize dest
	ft_strlcpy(dest, initial_dest, sizeof(dest));

	printf("\033[4mTest %d:\033[0m\n", test_number);
	printf("dest: \"%s\"\n", dest);
	printf("src: \"%s\"\n", src);
	printf("size: %zu\n", size);

	result = ft_strlcat(dest, src, size);

	printf("Resulting dest: \"%s\"\n", dest);
	printf("Return value: %zu\n", result);
	printf("---------------------------\n");
}

int main(void)
{
	printf("\n\033[4mTesting ft_strlcat :\033[0m\n\n");
	// Test 1: Normal concatenation
	test_ft_strlcat("Hello", " World", 50, 1);

	// Test 2: Size less than length of dest
	test_ft_strlcat("Hello", " World", 3, 2);

	// Test 3: Size exactly length of dest + 1
	test_ft_strlcat("Hello", "!", 6, 3);

	// Test 4: Size is zero
	test_ft_strlcat("Hello", " World", 0, 4);

	// Test 5: Empty dest
	test_ft_strlcat("", "Hello", 10, 5);

	// Test 6: Empty src
	test_ft_strlcat("Hello", "", 10, 6);

	// Test 7: Both dest and src are empty
	test_ft_strlcat("", "", 10, 7);

	// Test 8: Size less than dest length
	test_ft_strlcat("Hello", " World", 5, 8);

	return 0;
}