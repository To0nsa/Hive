
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
