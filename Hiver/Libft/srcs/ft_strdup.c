
#include <libft.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		src_length;

	if (!src)
		return (NULL);
	src_length = ft_strlen(src);
	copy = (char *)malloc((src_length + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}

/*## Function: ft_strdup
### Prototype:
 `char	*ft_strdup(const char *src)`

### Helper function prototype:
 `static char	*ft_strcpy(char *dest, const char *src)`

### Description:
 The `ft_strdup` function allocates memory and returns a duplicate of the input 
 string `src`. The function copies the contents of `src`, including the null 
 terminator, to the newly allocated memory.

### Parameters:
 - `const char *src`: A pointer to the string that will be duplicated.

### Return:
 - Returns a pointer to the newly allocated string that is a duplicate of `src`.
 - If memory allocation fails, the function returns `NULL`.

### Details:
 - The function first calculates the length of `src` using `ft_strlen`.
 - It allocates memory sufficient to store `src`, including the null terminator.
 - The function uses `ft_strcpy` to copy the contents of `src` to the allocated memory.
 - The function returns a pointer to the newly allocated string.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the duplicate 
 string to avoid memory leaks.*/
