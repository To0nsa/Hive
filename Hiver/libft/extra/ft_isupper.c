
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/*## Function: `ft_isupper`

 The `ft_isupper` function checks whether the given character `c` is an uppercase letter.
 Uppercase letters are defined as the characters between `'A'` and `'Z'` in the ASCII table.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is an uppercase letter (a character between `'A'` and `'Z'`),
 the function returns a non-zero value (true).
 - Zero: If `c` is not an uppercase letter, the function returns 0.*/
 