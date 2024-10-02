
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/*## Function: `ft_isspace`

 The `ft_isspace` function checks whether the given character `c` is a `whitespace`
 character. Whitespace characters include spaces, tabs, newlines, and other 
 characters that represent horizontal or vertical spacing.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a whitespace character (space, tab, newline, etc.),
 the function returns a non-zero value (true).
 - Zero: If `c` is not a whitespace character, the function returns 0.*/
 