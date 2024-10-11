
#include <libft.h>

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*## Function: ft_lstsize
### Prototype:
 `int ft_lstsize(t_list *lst)`

### Description:
 The `ft_lstsize` function counts and returns the number of nodes in the linked list 
 pointed to by `lst`.

### Parameters:
 - `t_list *lst`: A pointer to the first node of the linked list.

### Return:
 - The function returns the total number of nodes in the linked list.

### Details:
 - The function iterates through the list, incrementing a counter for each node.
 - It returns `0` if the list is empty (`lst == NULL`).
 - The list remains unchanged, as the function only traverses it without modifying any nodes.

### Important notes:
 - This function works for both empty and non-empty lists.
 - Ensure that the `lst` argument points to a valid list, or is `NULL` for an empty list.

### Examples of usage:
 1- Calculating the size of a dynamically allocated linked list to perform operations 
    like traversing, reversing, or removing elements.
 2- Useful when implementing list functions such as middle element finding, 
    splitting a list, or determining the end of a loop.*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstsize.c -L lib -lft -o test/test_ft_lstsize


