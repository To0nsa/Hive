
#include <libft.h>

size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
    while (str[len] != '\0')
        len++;
    return (len);
}

/*## Function: ft_strlen
### Prototype:
 `size_t	ft_strlen(const char *str)`

### Description:
 The `ft_strlen` function calculates the length of the string pointed to by
 `str`, excluding the null terminator (`\0`). It iterates through each 
 character in the string until the null terminator is encountered.

### Parameters:
 - `const char *str`: A pointer to the string whose length is to be measured.

### Return:
 - Returns the number of characters in the string `str`, not including the null terminator.
 - If `str` is `NULL`, the function returns `0`.

### Details:
 - The function initializes a variable `len` to store the length of the string.
 - It first checks if `str` is `NULL`. If so, it immediately returns `0` to 
 handle invalid input safely.
 - The function then enters a loop where it iterates through each character of
 `str`, counting the number of characters until the null terminator (`\0`) is encountered.
 - Once the null terminator is reached, the function returns the value of `len`,
 representing the total number of characters in the string.

### Important notes:
 - The null-terminator (`\0`) is not included in the returned length. The function only
 counts actual characters in the string.
 - Always ensure that the input string is valid and null-terminated before passing
 it to `ft_strlen` to avoid undefined behavior.*/
