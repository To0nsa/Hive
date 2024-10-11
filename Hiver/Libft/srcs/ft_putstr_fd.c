
#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
}

/*## Function: ft_putstr_fd
### Prototype:
 `void	ft_putstr_fd(char *s, int fd)`

### Description:
 The `ft_putstr_fd` function outputs the string `s` to the specified file 
 descriptor `fd`. The function writes the entire string to the file descriptor 
 using the `write` system call and calculates the length of the string using 
 `ft_strlen`.

### Parameters:
 - `char *s`: The string to output.
 - `int fd`: The file descriptor on which to write. This can be a file, standard 
 output, or standard error.

### Return:
 - None: This function does not return a value.

### Details:
 - The function first checks if the string `s` is not `NULL`. If `s` is `NULL`, 
 the function does nothing.
 - The function then uses the `write` system call to output the string to the file 
 descriptor `fd`.
 - The `write` function takes three arguments: the file descriptor, a pointer to 
 the data to write, and the number of bytes to write.
 - It calculates the length of the string using `ft_strlen`.

### Important notes:
 - The caller must ensure that the file descriptor `fd` is valid and open for 
 writing. If `fd` is invalid, the `write` system call will fail, but this 
 function does not handle such errors internally.
- The function will do nothing if `s` is `NULL`, ensuring safe execution.*/

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_putstr_fd.c -L lib -lft -o test/test_ft_putstr_fd

// ### Examples of usage:
/* #include <libft.h>

// Prototype of ft_putstr_fd
void	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	ft_putstr_fd("Testing ft_putstr_fd (writing to stdout):\n", 1);
	ft_putstr_fd("Test 1: Print a regular string\n", 1);
	ft_putstr_fd("Hello, world!\n", 1);
	ft_putstr_fd("Test 2: Print an empty string\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Test 3: Print a string with special characters\n", 1);
	ft_putstr_fd("~!@#$%^&*()_+\n", 1);
	ft_putstr_fd("Test 4: Print a numeric string\n", 1);
	ft_putstr_fd("1234567890\n", 1);
	ft_putstr_fd("Test 5: Print a string with multiple newlines\n", 1);
	ft_putstr_fd("Line1\nLine2\nLine3\n", 1);
	ft_putstr_fd("Test 6: Print a NULL string\n", 1);
	ft_putstr_fd(NULL, 1);
	return (0);
} */