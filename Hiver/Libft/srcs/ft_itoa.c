
#include <libft.h>

static int	ft_n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t 	len;
	long	nb;

	nb = n;
	len = ft_n_len(n);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

/*## Function: ft_itoa
### Prototype:
 `char	*ft_itoa(int n)`

### Description:
 The `ft_itoa` function converts an integer `n` into a null-terminated string 
 representation. It allocates memory dynamically for the string and handles both 
 positive and negative numbers. The function returns the string, or `NULL` if the 
 memory allocation fails.

### Parameters:
 - `int n`: The integer to convert into a string.

### Return:
 - Returns a pointer to the string representing the integer.
 - If memory allocation fails, the function returns `NULL`.

### Details:
 - The function first determines the number of digits in the integer (including 
 space for the negative sign if needed).
 - It allocates memory for the string, including the null terminator.
 - The function converts the integer to its string representation from the last 
 digit to the first, handling negative numbers by adding a minus sign.
 - It returns the allocated string.

### Important notes:
 - The caller is responsible for freeing the allocated memory to avoid memory 
 leaks.
 - If `n` is `0`, the function returns `"0"`.
 - The function handles the edge case for the minimum value of an integer (`INT_MIN`).*/
