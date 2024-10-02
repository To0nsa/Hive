
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
