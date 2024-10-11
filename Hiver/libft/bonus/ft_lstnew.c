#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*## Function: ft_lstnew
### Prototype:
 `t_list	*ft_lstnew(void *content)`

### Description:
 The `ft_lstnew` function allocates and returns a new node (element) for a linked
 list. The `content` parameter is used to initialize the `content` member of the
 new node. The `next` member is initialized to `NULL`.

### Parameters:
 - `void *content`: The content to create the new node with.

### Return:
 - Returns a pointer to the new node of type `t_list`.
 - If the allocation fails, the function returns `NULL`.

### Details:
 - The function uses `malloc` to allocate memory for a new `t_list` node.
 - The `content` pointer is assigned directly to the `content` member; it does not
   create a copy.
 - The `next` pointer of the new node is initialized to `NULL`.

### Important notes:
 - The caller is responsible for managing the memory of both the `content` and the
   new node.
 - Since `content` is a void pointer, it can point to any data type.
 - Be cautious when freeing the nodes to avoid memory leaks or invalid memory
   accesses.

### Examples of usage:
 1- Creating the head of a linked list: When starting a new linked list, `ft_lstnew`
    can be used to create the first node.

 2- Creating nodes with different content types: Since `content` is a `void *`, nodes
    can hold any type of data.

 3- Initializing nodes for data structures: Useful when constructing data structures
    that require dynamic linked lists.

 4- Storing pointers to dynamically allocated data: Nodes can hold pointers to any
    allocated data, allowing flexible list structures.
*/

// ### Compile: 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstnew.c -L lib -lft -o test/test_ft_lstnew

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

int main(void)
{
	// Test with string content
	char *str_content = "Hello, World!";
	t_list *node_str = ft_lstnew((void *)str_content);

	if (node_str == NULL)
	{
		printf("ft_lstnew returned NULL for string content\n");
		return (1);
	}
	if (node_str->content != str_content)
	{
		printf("node_str->content does not match the original string content\n");
		free(node_str);
		return (1);
	}
	if (node_str->next != NULL)
	{
		printf("node_str->next is not NULL for string content\n");
		free(node_str);
		return (1);
	}
	printf("Content of node_str: %s\n", (char *)node_str->content);
	printf("ft_lstnew test with string content passed\n");
	free(node_str);

    // Test with integer content
	int *int_content = malloc(sizeof(int));
	if (!int_content)
	{
		printf("Failed to allocate memory for int_content\n");
		return (1);
	}
	*int_content = 42;

	t_list *node_int = ft_lstnew((void *)int_content);

	if (node_int == NULL)
	{
		printf("ft_lstnew returned NULL for integer content\n");
		free(int_content);
		return (1);
    }
	if (node_int->content != int_content)
	{
		printf("node_int->content does not match the original integer content\n");
		free(node_int);
		free(int_content);
		return (1);
	}
	if (node_int->next != NULL)
	{
		printf("node_int->next is not NULL for integer content\n");
		free(node_int);
		free(int_content);
		return (1);
	}
	printf("Content of node_int: %ls\n", (int *)node_int->content);
	printf("ft_lstnew test with integer content passed\n");
	free(node_int);
	free(int_content);
	return (0);
}