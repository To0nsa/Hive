
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*## Function: `ft_isascii`

 The `ft_isprint` function checks whether the given character `c` is a printable
 ASCII character. Printable characters include all characters that have 
 a visible representation, such as letters, digits, punctuation marks, and 
 the space character (ASCII values from `32` to `126`).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a printable character (a character between 
 ASCII 32 and 126), the function returns a non-zero value (true).
 - Zero: If `c` is not a printable character, the function returns 0 (false).
 
### Important notes:
 - The function only considers characters in the standard printable ASCII
 range (32 to 126). Non-printable characters, such as control characters 
 (ASCII 0 to 31), and extended characters (above 126) will return false.*/
 