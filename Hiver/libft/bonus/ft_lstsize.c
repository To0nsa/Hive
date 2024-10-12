
#include "libft.h"

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

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Prototype of ft_lstsize
int	ft_lstsize(t_list *lst);

// Prototypes of helper functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
char	*ft_strdup(const char *src);

static void	del(void *content)
{
	free(content);
}

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
	int		size;

	printf("\033[4mTesting ft_lstsize\033[0m\n\n");

	// Test 1: Empty list
	size = ft_lstsize(list);
	printf("\033[4mTest 1:\033[0m Empty list size: %d\n\n", size);

	// Test 2: Single element
	char *content1 = ft_strdup("First Element"); // Use ft_strdup if available
	node = ft_lstnew(content1);
	ft_lstadd_front(&list, node);
	size = ft_lstsize(list);
	printf("\033[4mTest 2:\033[0m After adding one element, size: %d\n", size);
	ft_print_list(list);
	printf("\n");

	// Test 3: Multiple elements
	char *content2 = ft_strdup("Second Element");
	char *content3 = ft_strdup("Third Element");
	ft_lstadd_back(&list, ft_lstnew(content2));
	ft_lstadd_back(&list, ft_lstnew(content3));
	size = ft_lstsize(list);
	printf("\033[4mTest 3:\033[0m After adding three elements, size: %d\n", size);
	ft_print_list(list);
	printf("\n");

	// Test 4: Adding more elements
	char *content4 = ft_strdup("Fourth Element");
	ft_lstadd_front(&list, ft_lstnew(content4));
	size = ft_lstsize(list);
	printf("\033[4mTest 4:\033[0m After adding another element at front, size: %d\n", size);
	ft_print_list(list);
	printf("\n");

	// Test 5: Clearing the list
	ft_lstclear(&list, del);
	size = ft_lstsize(list);
	printf("\033[4mTest 5:\033[0m After clearing the list, size: %d\n", size);

	return (0);
}