
#include <libft.h>

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst == NULL || new == NULL)
        return;
    new->next = *lst;
    *lst = new;
}

/*## Function: ft_lstadd_front
### Prototype:
 `void ft_lstadd_front(t_list **lst, t_list *new)`

### Description:
 The `ft_lstadd_front` function adds a new node to the beginning of the list.
 The `new` node becomes the new head of the list, and its `next` pointer is 
 set to the current head of the list.

### Parameters:
 - `t_list **lst`: A pointer to the pointer to the first node of the list.
 - `t_list *new`: The new node to add to the front of the list.

### Return:
 - This function returns nothing (`void`).

### Details:
 - If `new` is `NULL`, the function does nothing.
 - If `lst` is `NULL` or the list is empty, the `new` node becomes the first node.
 - The `next` pointer of the new node is updated to point to the current first 
   node in the list.
 - Finally, the pointer to the list's head is updated to point to the new node.

### Important notes:
 - The caller is responsible for ensuring the `new` node is properly allocated.
 - Make sure the `new` node's `next` pointer is `NULL` if it is the only node 
   in the list.
 - Be careful not to lose reference to the original list head during the operation.

### Examples of usage:
 1- Adding a node to an empty list: `ft_lstadd_front` can be used to initialize 
    a list with a single node.
 2- Prepending nodes: Useful when nodes need to be inserted at the start of a 
    linked list, such as a stack implementation.*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstadd_front.c -L lib -lft -o test/test_ft_lstadd_front 

#include <stdio.h>
#include "libft.h"

// Prototype of ft_lstnew function
void	ft_lstadd_front(t_list **lst, t_list *new);

// Prototype of helper functions
t_list			*ft_lstnew(void *content);
char			*ft_strdup(const char *src);
void			ft_lstclear(t_list **lst, void (*del)(void *));
static void		ft_print_list(t_list *lst);
void			del(void *content);

// Helper function to print the list content
static void	ft_print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

// Del function implementation
void del(void *content)
{
	free(content);
}

int main(void)
{
	printf("\033[4mTesting ft_lstadd_front\033[0m\n");

	// Creating a node to be the initial head of the list with dynamically allocated content
	char *second_str = ft_strdup("Second");
	if (second_str == NULL)
	{
		printf("ft_strdup failed for 'Second'\n");
		return (1);
	}

	t_list *head = ft_lstnew((void *)second_str);
	if (head == NULL)
	{
		printf("ft_lstnew returned NULL for initial head node\n");
		free(second_str);
		return (1);
	}

	// Creating a new node to add at the front with dynamically allocated content
	char *first_str = ft_strdup("First");
	if (first_str == NULL)
	{
		printf("ft_strdup failed for 'First'\n");
		ft_lstclear(&head, del);
		return (1);
	}

	t_list *new_node = ft_lstnew((void *)first_str);
	if (new_node == NULL)
	{
		printf("ft_lstnew returned NULL for new node\n");
		free(first_str);
		ft_lstclear(&head, del);
		return (1);
	}

	// Before adding new_node
	printf("List before adding new node at the front:\n");
	ft_print_list(head);

	// Add new_node to the front
	ft_lstadd_front(&head, new_node);

	// After adding new_node
	printf("List after adding new node at the front:\n");
	ft_print_list(head);

	// Freeing the nodes using ft_lstclear
	ft_lstclear(&head, del);

	// Verify that the list is cleared
	printf("List after ft_lstclear:\n");
	ft_print_list(head);

	return (0);
}
