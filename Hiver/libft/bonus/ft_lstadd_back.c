
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/*## Function: ft_lstadd_back
### Prototype:
 `void ft_lstadd_back(t_list **lst, t_list *new)`

### Description:
 The `ft_lstadd_back` function adds a new node to the end of the list.
 The `new` node becomes the last element of the list, and the current last node's 
 `next` pointer is updated to point to the `new` node.

### Parameters:
 - `t_list **lst`: A pointer to the pointer to the first node of the list.
 - `t_list *new`: The new node to add to the end of the list.

### Return:
 - This function returns nothing (`void`).

### Details:
 - If `new` is `NULL`, the function does nothing.
 - If `lst` is `NULL` or the list is empty, the `new` node becomes the first node.
 - Otherwise, the function traverses the list to find the last node.
 - The `next` pointer of the last node is set to point to the `new` node.
 - The `new` node's `next` pointer is set to `NULL`, ensuring it is the new last node.

### Important notes:
 - The caller is responsible for ensuring the `new` node is properly allocated.
 - Ensure that the `new` node's `next` pointer is `NULL` before adding it to the list.
 - Avoid creating cycles in the list by properly managing the `next` pointers.

### Examples of usage:
 1- Adding a node to an empty list: `ft_lstadd_back` can be used to initialize 
    a list with a single node.
 2- Appending nodes: Useful when nodes need to be inserted at the end of a 
    linked list, such as building a queue or maintaining insertion order.*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstadd_back.c -L lib -lft -o test/test_ft_lstadd_back 

#include <stdio.h>
#include "libft.h"

// Prototype of ft_lstadd_back function
void	ft_lstadd_back(t_list **lst, t_list *new);

// Prototype of helper functions
t_list			*ft_lstnew(void *content);
char			*ft_strdup(const char *src);
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
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
	t_list *head = NULL;

	printf("\033[4mTesting ft_lstadd_back\033[0m\n");

	// Creating nodes with dynamically allocated content
	char *first_str = ft_strdup("First");
	if (first_str == NULL)
	{
		printf("ft_strdup failed for 'First'\n");
		return (1);
	}

	t_list *first_node = ft_lstnew((void *)first_str);
	if (first_node == NULL)
	{
		printf("ft_lstnew returned NULL for first node\n");
		free(first_str);
		return (1);
	}

	// Before adding any nodes
	printf("List before adding any nodes:\n");
	ft_print_list(head);

	// Add first_node to the back (should initialize the list)
	ft_lstadd_back(&head, first_node);

	// After adding first_node
	printf("List after adding first node at the back:\n");
	ft_print_list(head);

	// Creating a second node
	char *second_str = ft_strdup("Second");
	if (second_str == NULL)
	{
		printf("ft_strdup failed for 'Second'\n");
		ft_lstclear(&head, del);
		return (1);
	}

	t_list *second_node = ft_lstnew((void *)second_str);
	if (second_node == NULL)
	{
		printf("ft_lstnew returned NULL for second node\n");
		free(second_str);
		ft_lstclear(&head, del);
		return (1);
	}

	// Add second_node to the back
	ft_lstadd_back(&head, second_node);

	// After adding second_node
	printf("List after adding second node at the back:\n");
	ft_print_list(head);

	// Creating a third node
	char *third_str = ft_strdup("Third");
	if (third_str == NULL)
	{
		printf("ft_strdup failed for 'Third'\n");
		ft_lstclear(&head, del);
		return (1);
	}

	t_list *third_node = ft_lstnew((void *)third_str);
	if (third_node == NULL)
	{
		printf("ft_lstnew returned NULL for third node\n");
		free(third_str);
		ft_lstclear(&head, del);
		return (1);
	}

	// Add third_node to the back
	ft_lstadd_back(&head, third_node);

	// After adding third_node
	printf("List after adding third node at the back:\n");
	ft_print_list(head);

	// Freeing the nodes using ft_lstclear
	ft_lstclear(&head, del);

	// Verify that the list is cleared
	printf("List after ft_lstclear:\n");
	ft_print_list(head);

	return (0);
}
