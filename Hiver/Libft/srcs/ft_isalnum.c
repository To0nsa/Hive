
#include <libft.h>

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*## Function: `ft_isalnum`

 The `ft_isalnum` function checks whether the given character `c` is an alphanumeric
 character. An alphanumeric character is defined as either a letter (alphabetic 
 character) or a digit (numeric character). This function relies on two other
 functions: `ft_isalpha` (to check if `c` is a letter) and `ft_isdigit` (to check if `c` 
 is a digit).

### Parameters:
 - `int c`: The character to be checked. The argument is typically passed as
 an `unsigned char` cast to `int`, or `EOF`.

### Return:
 - Non-zero value: If `c` is either a letter (A-Z, a-z) or a digit (0-9), 
 the function returns a non-zero value.
 - Zero: If `c` is neither a letter nor a digit, the function returns 0.
 
### Important notes:
 - This function assumes that the input is representable as an `unsigned char` or is `EOF`.
 Passing a value outside this range may lead to undefined behavior.*/
