
#include <libft.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*## Function: ft_putchar_fd
### Prototype:
 `void	ft_putchar_fd(char c, int fd)`

### Description:
 The `ft_putchar_fd` function outputs the character `c` to the file descriptor 
 specified by `fd`. It writes the character using the `write` system call.

### Parameters:
 - `char c`: The character to output.
 - `int fd`: The file descriptor where the character will be written. This can 
 refer to standard output, standard error, or any open file.

### Details:
 - The function calls the `write` system call to send the character `c` to the 
 specified file descriptor `fd`.
 - The `write` function requires three parameters: the file descriptor, a pointer 
 to the data to write, and the number of bytes to write (in this case, `1` byte 
 for a single character).
 - This function is commonly used for writing characters to files or output streams.

### Important notes:
 - The caller must ensure that the file descriptor `fd` is valid and open for 
 writing. If `fd` is invalid, the `write` system call will fail, but this 
 function does not handle such errors internally.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_putchar_fd.c -L lib -lft -o test/test_ft_putchar_fd

// ### Examples of usage:
#include <libft.h>

// Prototype of ft_putchar_fd
void	ft_putchar_fd(char c, int fd);

// Prototype of helper functions
void	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	// Basic tests to print characters to stdout (fd 1)
	ft_putstr_fd("Testing ft_putchar_fd (writing to stdout):\n", 1);

	// Test 1: Printing a regular character 'A'
	ft_putstr_fd("Test 1 -> Expected output: A - output -> ", 1);
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	// Test 2: Printing a digit character '5'
	ft_putstr_fd("Test 2 -> Expected output: 5 - output -> ", 1);
	ft_putchar_fd('5', 1);
	ft_putchar_fd('\n', 1);

	// Test 3: Printing a special character '@'
	ft_putstr_fd("Test 3 -> Expected output: @ - output -> ", 1);
	ft_putchar_fd('@', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
