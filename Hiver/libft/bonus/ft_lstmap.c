
#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			if (del != NULL)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*## Function: ft_lstmap
### Prototype:
 `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`

### Description:
 The `ft_lstmap` function iterates over a linked list `lst` and applies the
 function `f` to the content of each node, creating a new list resulting
 from the successive applications of `f`. The `del` function is used to delete
 the content of a node if needed, particularly in case of an allocation failure.

### Parameters:
 - `t_list *lst`: The head of the linked list to iterate over.
 - `void *(*f)(void *)`: A pointer to the function that will be applied to
 the content of each node.
 - `void (*del)(void *)`: A pointer to the function used to delete the
 content of a node if necessary.

### Return:
 - A new linked list where each node's content is the result of the function
 `f` applied to the original node's content.
 - If an allocation fails during the process, the function returns `NULL`,
 and the `del` function is used to free the allocated memory.

### Details:
 - If either `lst` or `f` is `NULL`, the function returns `NULL`.
 - The function initializes a new list `new_list` to `NULL`.
 - It iterates through each node of the original list `lst`:
   - Applies the function `f` to the content of the current node, storing 
   the result in `new_content`.
   - Creates a new node `new_node` with `new_content` using `ft_lstnew`.
   - If `new_node` is `NULL` (allocation failure):
     - If `del` is not `NULL`, it applies `del` to `new_content` to free
	 any allocated memory.
     - Clears the entire `new_list` using `ft_lstclear` to prevent memory leaks.
     - Returns `NULL`.
   - Adds `new_node` to the end of `new_list` using `ft_lstadd_back`.
   - Moves to the next node in the original list.
 - After the iteration, returns the new list `new_list`.

### Important notes:
 - The `f` function should allocate new memory for the content if necessary,
 especially if the content is complex data.
 - The `del` function must properly free the content to prevent memory leaks
 in case of failure.
 - This function creates a completely new list; it does not modify the original list.
 - Be cautious with memory management to avoid leaks and dangling pointers. */

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstmap.c -L lib -lft -o test/test_ft_lstmap

#include <stdio.h>
#include "libft.h"

// Prototype of ft_lstmap function
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Prototype of helper functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*ft_strdup(const char *src);
int		ft_toupper(int c);

// Sample function to apply: Convert string to uppercase
void	*to_uppercase_content(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	if (content == NULL)
		return (NULL);
	str = (char *)content;
	new_str = ft_strdup(str);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = ft_toupper(new_str[i]);
		i++;
	}
	return ((void *)new_str);
}

// Del function implementation
void	del(void *content)
{
	free(content);
}

// Helper function to print the list content using ft_lstiter
void	print_content(void *content)
{
	if (content)
		printf("%s -> ", (char *)content);
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

	printf("\033[4mTesting ft_lstmap\033[0m\n");

	// Before applying ft_lstmap
	printf("Original list:\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	// Apply ft_lstmap with to_uppercase_content function
	t_list	*new_list = ft_lstmap(head, to_uppercase_content, del);
	if (new_list == NULL)
	{
		printf("ft_lstmap returned NULL\n");
		ft_lstclear(&head, del);
		return (1);
	}

	// After applying ft_lstmap
	printf("New list after ft_lstmap (to_uppercase_content):\n");
	ft_lstiter(new_list, print_content);
	printf("NULL\n");

	// Freeing the original list
	ft_lstclear(&head, del);

	// Freeing the new list
	ft_lstclear(&new_list, del);

	return (0);
}

