
#include "libft.h"

static void del(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}

/*## Function: ft_lstclear
### Prototype:
 `void ft_lstclear(t_list **lst, void (*del)(void *))`

### Description:
 The `ft_lstclear` function deletes and frees each node of the list using the 
 provided `del` function, and then sets the list pointer to `NULL`. This effectively 
 clears the entire linked list, ensuring that all allocated memory is properly freed.

### Parameters:
 - `t_list **lst`: A pointer to the pointer to the first node of the list.
 - `void (*del)(void *)`: A pointer to the function used to delete the content of each node.

### Return:
 - This function returns nothing (`void`).

### Details:
 - If `lst` is `NULL` or `del` is `NULL`, the function does nothing.
 - Iterates through each node in the list:
   - Uses `ft_lstdelone` to delete the current node's content and free the node.
   - Moves to the next node in the list.
 - After all nodes are deleted, sets the list pointer `*lst` to `NULL` to indicate that the list is empty.

### Important notes:
 - The `del` function is responsible for freeing the content of each node to prevent memory leaks.
 - After calling `ft_lstclear`, the original list pointer is set to `NULL`, so it should not be used unless reinitialized.
 - Ensure that the list is properly initialized before calling `ft_lstclear` to avoid undefined behavior.

### Examples of usage:
 1 - Clearing a list before exiting a program.

 2 - Resetting a list in a loop.
  
 3 - Cleaning up resources in error handling. */