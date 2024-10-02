
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}

/*## Function: `ft_tolower`

 The `ft_tolower` function converts an uppercase alphabetic character to
 its corresponding lowercase equivalent. If the input character `c` is an
 uppercase letter (`'A'` to `'Z'`), it is converted to the corresponding lowercase
 letter. If `c` is not an uppercase letter, it is returned unchanged. 

### Parameters:
 - `int c`: The character to be converted. The argument is typically passed as 
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - If `c` is an uppercase letter, the function returns the corresponding lowercase letter.
 - If `c` is not an uppercase letter, the function returns `c` unchanged.*/
 