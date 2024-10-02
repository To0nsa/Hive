
#include <libft.h>

static int	ft_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static size_t	ft_trim_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_trim_end(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && ft_is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set);
	if (start >= end)
	{
		trimmed_str = (char *)malloc(sizeof(char));
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, s1 + start, end - start);
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}

/*## Function: ft_strtrim
### Prototype:
 `char	*ft_strtrim(const char *s1, const char *set)`

### Helper functions prototypes:
 `static int		ft_is_in_set(char c, const char *set)`
 `static size_t		ft_trim_start(const char *s1, const char *set)`
 `static size_t		ft_trim_end(const char *s1, const char *set)`
 `static char		*ft_strncpy(char *dest, const char *src, size_t n)`

### Description:
 The `ft_strtrim` function trims the characters from the string `s1` that are 
 present in the set `set`. It removes characters from both the beginning and the 
 end of the string, returning a newly allocated trimmed string.

### Parameters:
 - `const char *s1`: A pointer to the original string that will be trimmed.
 - `const char *set`: A pointer to the string containing the characters to be 
 removed from both the beginning and end of `s1`.

### Return:
 - Returns a pointer to the newly allocated trimmed string.
 - If memory allocation fails or if either `s1` or `set` is `NULL`, the function 
 returns `NULL`.
 - If all characters are trimmed, the function returns an empty string 
 (allocated with `malloc`).

### Details:
 - The function first checks if the input strings `s1` or `set` are `NULL`, and if 
 so, returns `NULL`.
 - It uses the helper function `ft_trim_start` to find the first position in `s1` 
 that is not part of `set`.
 - It then calls `ft_trim_end` to find the last valid character of `s1` not 
 contained in `set`.
 - If the `start` index is greater than or equal to the `end` index, the function 
 allocates an empty string and returns it.
 - The function allocates memory for the trimmed substring (`end - start + 1`) and 
 copies the relevant portion using `ft_strncpy`.
 - The resulting string is null-terminated before being returned.

### Important notes:
 - The caller is responsible for freeing the allocated memory for the trimmed 
 string to avoid memory leaks.
 - If all characters in the input string are part of the set, the function returns 
 an empty string, not `NULL`.
 - Ensure memory allocation is successful by checking for a `NULL` return before 
 using the result.*/