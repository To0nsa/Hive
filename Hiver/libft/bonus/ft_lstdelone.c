
#include <libft.h>

static void del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*## Function: ft_lstdelone
### Prototype:
 `void ft_lstdelone(t_list *lst, void (*del)(void *))`

### Description:
 The `ft_lstdelone` function deletes a single node from a linked list. It applies the 
 provided `del` function to the content of the node to properly free any dynamically 
 allocated memory within the node's content, and then frees the node itself.

### Parameters:
 - `t_list *lst`: The node to be deleted.
 - `void (*del)(void *)`: A pointer to the function used to delete the content of the node.

### Return:
 - This function returns nothing (`void`).

### Details:
 - If either `lst` or `del` is `NULL`, the function does nothing.
 - The `del` function is applied to the `content` of the node to handle any necessary 
   deallocation of the data stored within the node.
 - After the content is deleted, the node itself is freed to release the memory allocated 
   for the node structure.
 - This function does not handle updating any pointers in the list; it solely focuses on 
   deleting the specified node.

### Important notes:
 - The caller must ensure that the node to be deleted (`lst`) is part of a linked list 
   and that no other pointers reference it after deletion to prevent dangling pointers.
 - The `del` function must correctly handle the deallocation of the node's content to 
   avoid memory leaks.
 - Use this function when a single node needs to be removed from a list, such as during 
   node-specific deletion operations or error handling where specific nodes must be 
   freed.

### Examples of usage:
 1 - Deleting a specific node in a list.
 2 - Handling errors by deleting a node before exiting a function.
 3 - Removing a node during list traversal.*/
