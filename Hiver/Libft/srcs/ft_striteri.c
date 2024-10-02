
#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*## Function: ft_striteri
### Prototype:
 `void	ft_striteri(char *s, void (*f)(unsigned int, char*))`

### Description:
 The `ft_striteri` function applies the function `f` to each character of the 
 string `s`. The function `f` takes the index of the character as the first 
 argument and a pointer to the character as the second argument, allowing 
 modification of the characters in place.

### Parameters:
 - `char *s`: The string to iterate over.
 - `void (*f)(unsigned int, char*)`: A pointer to the function that is applied to 
 each character of the string. This function takes two parameters: an unsigned 
 integer (the index of the character) and a pointer to the character itself.

### Return:
 - None: This function does not return a value.

### Details:
 - The function iterates over the string `s`, passing the index and the address 
 of each character to the function `f` for modification.
 - The string `s` is modified in place.

### Important notes:
 - The function assumes that the string `s` is null-terminated.
 - If `s` or `f` is `NULL`, the function does nothing.*/