
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
