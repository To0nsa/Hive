
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*## Function: `ft_isdigit`

 The `ft_isdigit` function checks whether the given character c is
 a decimal digit (i.e., a number from `'0'` to `'9'`).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a digit (a character between `'0'` and `'9'`),
 the function returns a non-zero value (true).
 - Zero: If `c` is not a digit, the function returns 0.*/
