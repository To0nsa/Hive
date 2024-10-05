
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

/*## Function: `ft_toupper`

 The `ft_toupper` function converts a lowercase alphabetic character to
 its corresponding uppercase equivalent. If the input character `c` is an
 lowercase letter (`'a'` to `'z'`), it is converted to the corresponding uppercase
 letter. If `c` is not an lowercase letter, it is returned unchanged. 

### Parameters:
 - `int c`: The character to be converted. The argument is typically passed as 
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - If `c` is a lowercase letter, the function returns the corresponding uppercase letter.
 - If `c` is not an lowercase letter, the function returns `c` unchanged.*/