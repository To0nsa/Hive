
#include <libft.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcpy(new_str + ft_strlen(s1), s2);
	return (new_str);
}

/*## Function: ft_strjoin
### Prototype:
 `char	*ft_strjoin(const char *s1, const char *s2)`

### Helper function prototype:
 `static char	*ft_strcpy(char *dest, const char *src)`

### Description:
 The `ft_strjoin` function concatenates two strings, `s1` and `s2`, into a new 
 string. The function allocates memory for the new string, copies `s1` followed 
 by `s2`, and returns the result. The resulting string is null-terminated.

### Parameters:
 - `const char *s1`: A pointer to the first string to be joined.
 - `const char *s2`: A pointer to the second string to be joined.

### Return:
 - Returns a pointer to the newly allocated string that contains the concatenation
 of `s1` and `s2`.
 - If memory allocation fails or if either `s1` or `s2` is `NULL`, the function 
 returns `NULL`.

### Details:
 - The function first checks if either `s1` or `s2` is `NULL`. If either is 
 `NULL`, the function returns `NULL`.
 - It calculates the total length of the new string by adding the lengths of `s1` 
 and `s2` using `ft_strlen`.
 - Memory is allocated for the new string, with enough space for both strings and 
 the null terminator.
 - The function uses the helper `ft_strcpy` to copy `s1` to the new string.
 - It then appends `s2` to the new string by copying it right after the end of `s1`.
 - The new string is null-terminated and returned to the caller.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the resulting 
 string to avoid memory leaks.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/
