
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*## Function: `ft_isascii`

 The `ft_isascii` function checks whether the given character `c` is an ASCII character.
 ASCII (American Standard Code for Information Interchange) is a character encoding
 standard that represents text characters in the range of `0` to `127`.

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is a valid ASCII character (i.e., it falls within the range
 of 0 to 127), the function returns a non-zero value (true).
 - Zero: If c is outside the ASCII range (i.e., less than 0 or greater than 127),
 the function returns 0 (false).
 
### Important notes:
 - The function specifically checks for the ASCII range (0–127). Characters outside
 this range (such as extended ASCII or Unicode characters) will return false.*/