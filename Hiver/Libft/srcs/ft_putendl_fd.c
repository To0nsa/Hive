
#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*## Function: ft_putendl_fd
### Prototype:
 `void	ft_putendl_fd(char *s, int fd)`

### Description:
 The `ft_putendl_fd` function outputs the string `s` to the file descriptor 
 specified by `fd`, followed by a newline character (`'\n'`). The function uses 
 the `write` system call to perform the output.

### Parameters:
 - `char *s`: The string to output.
 - `int fd`: The file descriptor on which to write. This can be standard output, 
 standard error, or any valid open file.

### Return:
 - None: This function does not return a value.

### Details:
 - The function first checks if the string `s` is not `NULL`. If `s` is `NULL`, 
 the function does nothing.
 - The function writes the string `s` to the file descriptor `fd` using the `write`
 system call. It then writes a newline character (`'\n'`) to the same file 
 descriptor.
 - The `write` function takes three arguments: the file descriptor, a pointer to 
 the data to write, and the number of bytes to write.

### Important notes:
 - The caller must ensure that the file descriptor `fd` is valid and open for 
 writing. If `fd` is invalid, the `write` system call will fail, but this 
 function does not handle such errors internally.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_putendl_fd.c -L lib -lft -o test/test_ft_putendl_fd

// ### Examples of usage:
#include <libft.h>

// Prototype of ft_putendl_fd
void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	// Testing ft_putendl_fd by writing strings to stdout (fd 1)
	ft_putendl_fd("Testing ft_putendl_fd (writing to stdout):", 1);

	// Test 1: Printing a simple string "Hello World"
	ft_putendl_fd("Test 1: Expected output -> Hello World", 1);
	ft_putendl_fd("Hello World", 1);

	// Test 2: Printing a string with special characters
	ft_putendl_fd("Test 2: Expected output -> ~!@#$%^&*()_+", 1);
	ft_putendl_fd("~!@#$%^&*()_+", 1);

	// Test 3: Printing a numeric string
	ft_putendl_fd("Test 3: Expected output -> 1234567890", 1);
	ft_putendl_fd("1234567890", 1);

	// Test 4: Printing an empty string
	ft_putendl_fd("Test 4: Expected output -> (empty line)", 1);
	ft_putendl_fd("", 1);

	// Test 5: Printing a string with a newline at the end
	ft_putendl_fd("Test 5: Expected output -> Line with newline", 1);
	ft_putendl_fd("Line with newline\n", 1);

	return (0);
}
