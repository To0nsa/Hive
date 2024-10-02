
#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0' &&
			i + j < len && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*## Function: ft_strnstr
### Prototype:
 `char	*ft_strnstr(const char *big, const char *little, size_t len)`

### Description:
 The `ft_strnstr` function locates the first occurrence of the substring `little`
 in the string `big`, where no more than `len` characters are searched. If 
 `little` is an empty string, `big` is returned. If `little` is not found 
 within `len` characters, the function returns `NULL`.

### Parameters:
 - `const char *big`: The string in which to search for `little`.
 - `const char *little`: The substring to search for.
 - `size_t len`: The maximum number of characters to search.

### Return:
 - Returns a pointer to the first occurrence of `little` in `big` if found.
 - If `little` is an empty string, the function returns `big`.
 - If `little` is not found within the first `len` characters, the function 
 returns `NULL`.

### Details:
 - If `little` is an empty string, `big` is returned immediately.
 - The function searches for the substring `little` in `big` while ensuring 
 that it doesn't search beyond the first `len` characters.
 - The function compares characters of `little` to `big`, checking for a match.
 - If a match is found within the given limit (`len`), a pointer to the start of 
 the match is returned.
 - If no match is found or if `len` is too small, the function returns `NULL`.*/
