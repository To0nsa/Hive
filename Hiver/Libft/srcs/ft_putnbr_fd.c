
#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

/*## Function: ft_putnbr_fd
### Prototype:
 `void	ft_putnbr_fd(int n, int fd)`

### Description:
 The `ft_putnbr_fd` function outputs the integer `n` to the file descriptor `fd`. 
 The function uses recursion to handle multi-digit integers, writing each digit 
 to the file descriptor one by one. If the integer is negative, a minus sign 
 is output before the digits.

### Parameters:
 - `int n`: The integer to output.
 - `int fd`: The file descriptor on which to write. This can be standard output, 
 standard error, or any valid file descriptor.

### Return:
 - None: This function does not return a value.

### Details:
 - The function uses recursion to break down the integer into its individual 
 digits. It writes each digit to the file descriptor using the `write` system 
 call.
 - If `n` is negative, the function first outputs the minus sign, then processes 
 the absolute value of the number.
 - The function uses the `write` system call to output each character representing 
 a digit.

### Important notes:
 - The caller must ensure that the file descriptor `fd` is valid and open for 
 writing. If `fd` is invalid, the `write` system call will fail, but this 
 function does not handle such errors internally.*/
