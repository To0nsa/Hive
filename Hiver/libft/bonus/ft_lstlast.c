
#include <libft.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* ### Description:
 The ft_lstlast function traverses a linked list and returns a pointer to the last node in the list.

Parameters:
t_list *lst: A pointer to the first node of the linked list.
Return:
Returns a pointer to the last node of the linked list.
Returns NULL if the list is empty (lst == NULL).
Details:
The function iterates through the list until it reaches the node where next is NULL.
It does not modify the list in any way; it only traverses it to find the last node.
If the list is empty, it safely returns NULL.
Important Notes:
Ensure that the lst argument points to a valid list or is NULL for an empty list.
This function is useful for operations that require access to the end of the list, such as adding a new node to the end.
Examples of Usage:
Appending Elements: When implementing a function to add elements to the end of the list, ft_lstlast can be used to find the current last node.
Traversal Operations: Useful in scenarios where you need to perform operations starting from the end of the list. */

/*## Function: ft_lstnew
### Prototype:
 `t_list	*ft_lstnew(void *content)`

### Description:
 The ft_lstlast function traverses a linked list and returns a pointer to the last node in the list

### Parameters:
 - t_list *lst: A pointer to the first node of the linked list.

### Return:
 - Returns a pointer to the last node of the linked list.
 - Returns NULL if the list is empty (lst == NULL).

### Details:
 - The function iterates through the list until it reaches the node where next is NULL.
 - It does not modify the list in any way; it only traverses it to find the last node.
 - If the list is empty, it safely returns NULL.

### Important notes:
 - Ensure that the lst argument points to a valid list or is NULL for an empty list.
 - This function is useful for operations that require access to the end of the list,
 such as adding a new node to the end.

### Examples of usage:
 1 - Appending Elements: When implementing a function to add elements to the end of the list,
 ft_lstlast can be used to find the current last node.
 
 2 - Traversal Operations: Useful in scenarios where you need to perform operations 
 starting from the end of the list.*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstlast.c -L lib -lft -o test/test_ft_lstlast

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Prototype of ft_lstlast
t_list	*ft_lstlast(t_list *lst);

// Prototypes of helper functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
char	*ft_strdup(const char *src);

// Helper function to free node content
static void	del(void *content)
{
	free(content);
}

// Helper function to print the list
static void	ft_print_list(t_list *lst)
{
	int	i = 0;
	while (lst)
	{
		printf("Node %d: %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main()
{
	t_list	*list = NULL;
	t_list	*node;
	t_list	*last;
	char	*content;

	printf("\033[4mTesting ft_lstlast\033[0m\n\n");

	// Test 1: Empty list
	last = ft_lstlast(list);
	printf("\033[4mTest 1:\033[0m Empty list last node: %p\n\n", (void *)last);

	// Test 2: Single element
	content = ft_strdup("Only Element");
	if (!content)
	{
		printf("ft_strdup failed");
		return (1);
	}
	node = ft_lstnew(content);
	if (!node)
	{
		printf("ft_lstnew failed");
		free(content);
		return (1);
	}
	ft_lstadd_front(&list, node);
	last = ft_lstlast(list);
	printf("\033[4mTest 2:\033[0m Single element last node content: %s\n", (char *)last->content);
	ft_print_list(list);
	printf("\n");

	// Test 3: Multiple elements
	char *content2 = ft_strdup("Second Element");
	char *content3 = ft_strdup("Third Element");
	if (!content2 || !content3)
	{
		printf("ft_strdup failed");
		ft_lstclear(&list, del);
		return (1);
	}
	ft_lstadd_back(&list, ft_lstnew(content2));
	ft_lstadd_back(&list, ft_lstnew(content3));
	last = ft_lstlast(list);
	printf("\033[4mTest 3:\033[0m Multiple elements last node content: %s\n", (char *)last->content);
	ft_print_list(list);
	printf("\n");

	// Test 4: Adding another element at front
	char *content4 = ft_strdup("Fourth Element");
	if (!content4)
	{
		printf("ft_strdup failed");
		ft_lstclear(&list, del);
		return (1);
	}
	ft_lstadd_front(&list, ft_lstnew(content4));
	last = ft_lstlast(list);
	printf("\033[4mTest 4:\033[0m After adding another element at front, last node content: %s\n", (char *)last->content);
	ft_print_list(list);
	printf("\n");

	// Test 5: Clearing the list
	ft_lstclear(&list, del);
	last = ft_lstlast(list);
	printf("\033[4mTest 5:\033[0m After clearing the list, last node: %p\n", (void *)last);

	return (0);
}



