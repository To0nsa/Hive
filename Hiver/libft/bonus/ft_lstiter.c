
#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*## Function: ft_lstiter
### Prototype:
 `void ft_lstiter(t_list *lst, void (*f)(void *))`

### Description:
 The `ft_lstiter` function iterates through each node of the linked list `lst` and applies the function `f` to the content of each node. This allows for operations to be performed on each element of the list, such as printing, modifying, or processing the data stored within each node.

### Parameters:
 - `t_list *lst`: The head of the linked list to iterate over.
 - `void (*f)(void *)`: A pointer to the function that will be applied to the content of each node.

### Return:
 - This function returns nothing (`void`).

### Details:
 - If either `lst` or `f` is `NULL`, the function does nothing.
 - The function starts at the head of the list and traverses each node sequentially.
 - For each node, the function `f` is called with the node's `content` as its argument.
 - The traversal continues until the end of the list is reached (`lst` becomes `NULL`).
 - This function does not modify the structure of the list; it only applies the function to each node's content.

### Important notes:
 - The function `f` should be designed to handle the type of data stored in the list's `content`.
 - Ensure that `f` does not alter the `next` pointers of the nodes to maintain the integrity of the list structure.
 - This function is useful for performing read-only operations or operations that do not require altering the list's linkage.

### Examples of usage:
 1 - Printing all elements in a list.
 2 - Modifying all elements in a list.
 3 - Applying a complex transformation to each element. */

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstiter.c -L lib -lft -o test/test_ft_lstiter

#include <stdio.h>
#include "libft.h"

// Prototype of ft_lstiter function
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Prototype of helper functions
t_list	*ft_lstnew(void *content);
char	*ft_strdup(const char *src);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_toupper(int c);

// Helper function to print the list content using ft_lstiter
void	print_content(void *content)
{
	if (content)
		printf("%s -> ", (char *)content);
}

// Del function implementation
void	del(void *content)
{
	free(content);
}

// Sample function to apply: Convert string to uppercase using ft_toupper
void	to_uppercase(void *content)
{
	if (content)
	{
		char *str = (char *)content;
		while (*str)
		{
			*str = ft_toupper(*str); // Using ft_toupper for conversion
			str++;
		}
	}
}

int	main(void)
{
	// Creating nodes with dynamically allocated content
	char	*first_str = ft_strdup("first");
	char	*second_str = ft_strdup("second");
	char	*third_str = ft_strdup("third");

	if (!first_str || !second_str || !third_str)
	{
		printf("ft_strdup failed\n");
		free(first_str);
		free(second_str);
		free(third_str);
		return (1);
	}

	t_list	*head = ft_lstnew((void *)first_str);
	t_list	*second_node = ft_lstnew((void *)second_str);
	t_list	*third_node = ft_lstnew((void *)third_str);

	if (!head || !second_node || !third_node)
	{
		printf("ft_lstnew returned NULL\n");
		ft_lstclear(&head, del);
		ft_lstclear(&second_node, del);
		ft_lstclear(&third_node, del);
		return (1);
	}

	// Linking the nodes manually
	head->next = second_node;
	second_node->next = third_node;

	printf("\033[4mTesting ft_lstiter\033[0m\n");

	// Before applying ft_lstiter (printing the list)
	printf("List before ft_lstiter:\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	// Apply ft_lstiter with to_uppercase function
	ft_lstiter(head, to_uppercase);

	// After applying ft_lstiter (printing the modified list)
	printf("List after ft_lstiter (to_uppercase):\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	// Freeing the nodes using ft_lstclear
	ft_lstclear(&head, del);

	// Verify that the list is cleared by attempting to print it
	printf("List after ft_lstclear:\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	return (0);
}