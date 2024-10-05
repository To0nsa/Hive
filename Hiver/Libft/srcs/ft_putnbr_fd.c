
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

// ### Compile:
// cc -Wall -Wextra -Werror -I include srcs/ft_putnbr_fd.c -L lib -lft -o test/test_ft_putnbr_fd

// ### Examples of usage:
#include <libft.h>

// Prototype of ft_putnbr_fd
void	ft_putnbr_fd(int n, int fd);

// Prototype of helper functions
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	// Testing ft_putnbr_fd by writing integers to stdout (fd 1)
	ft_putstr_fd("Testing ft_putnbr_fd (writing to stdout):\n", 1);

	// Test 1: Print a positive number
	ft_putendl_fd("Test 1: Expected output -> 12345", 1);
	ft_putnbr_fd(12345, 1);
	ft_putchar_fd('\n', 1);

	// Test 2: Print a negative number
	ft_putendl_fd("Test 2: Expected output -> -9876", 1);
	ft_putnbr_fd(-9876, 1);
	ft_putchar_fd('\n', 1);

	// Test 3: Print zero
	ft_putendl_fd("Test 3: Expected output -> 0", 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);

	// Test 4: Print the maximum integer
	ft_putendl_fd("Test 4: Expected output -> 2147483647", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);

	// Test 5: Print the minimum integer (-2147483648)
	ft_putendl_fd("Test 5: Expected output -> -2147483648", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);

	return (0);
}
