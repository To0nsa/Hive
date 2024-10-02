
int	ft_ispunct(int c)
{
	return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') 
		|| (c >= '[' && c <= '`') || (c >= '{' && c <= '~'));
}

/*## Function: `ft_ispunct`

 The `ft_ispunct` function checks whether the given character `c` is a punctuation
 character. Punctuation characters are characters that are not alphanumeric
 (letters or digits) and are not whitespace. This includes symbols such as `!`, `@`, 
 `#`, and various others in the ASCII table.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a punctuation character, the function returns
 a non-zero value (true).
 - Zero: If `c` is not a punctuation character, the function returns 0.*/
