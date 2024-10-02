 
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*## Function: ft_isalpha

 The ft_isalpha function checks whether the given character `c` is an alphabetic
 character. An alphabetic character is defined as any uppercase letter (A to Z)
 or lowercase letter (a to z).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is an alphabetic character (either uppercase 
 or lowercase), the function returns a non-zero value (true).
 - Zero: If c is not an alphabetic character, the function returns 0.
 
### Important notes:
 - This function assumes that the input is representable as an `unsigned char` or `EOF`.
 Passing a value outside this range may lead to undefined behavior.
 - This function does not account for any locale-specific alphabetic characters
 (e.g., accented letters). It only works for standard ASCII alphabetic characters. */
