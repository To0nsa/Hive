
int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/*## Function: `ft_islower`

 The ft_islower function checks whether the given character `c` is a lowercase letter.
 Lowercase letters are defined as the characters between `'a'` and `'z'` in the ASCII table.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a lowercase letter (a character between `'a'` and `'z'`),
 the function returns a non-zero value (true).
 - Zero: If `c` is not a lowercase letter, the function returns 0.*/
 