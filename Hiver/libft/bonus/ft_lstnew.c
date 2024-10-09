#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

/*## Function: ft_lstnew
### Prototype:
 `t_list	*ft_lstnew(void *content)`

### Description:
 The `ft_lstnew` function allocates (with `malloc`) and returns a new element
 of a linked list. The `content` variable of the new element is initialized with
 the value of the parameter `content`. The `next` pointer is initialized to `NULL`.

### Parameters:
 - `void *content`: The content to create the new element with.

### Return:
 - Returns a pointer to the new element.
 - If the allocation fails, the function returns `NULL`.

### Details:
 - The function allocates memory for a new `t_list` element.
 - It initializes the `content` member of the new element with the provided `content`.
 - The `next` pointer is set to `NULL`, indicating that the new element
 does not point to any other element yet.

### Important notes:
 - The user is responsible for managing the memory allocated by this function.
 - The `content` can be any data type, as it is a `void *`. It is up to the user
 to ensure that the content is properly managed.*/

// ### Compile : 
// cc -Wall -Wextra -Werror -I include bonus/ft_lstnew.c -L lib -lft -o test/test_ft_lstnew


#include <libft.h>
#include <stdio.h>

// Prototype of ft_lstnew
t_list	*ft_lstnew(void *content);

// Prototype of helper functions
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

typedef struct	s_test_case
{
	void		*content;
	const char	*description;
}				t_test_case;

int	main(void)
{
	// Prepare content for test cases
	int		*int_content = malloc(sizeof(int));
	if (int_content)
		*int_content = 42;

	char	*str_content = malloc(6);
	if (str_content)
		ft_strlcpy(str_content, "Hello", 6);

	char	*str_content2 = "Another test";

	// Define test cases using the struct
	t_test_case tests[] = {
		{str_content, "Create a new list element with dynamically allocated string content"},
		{NULL, "Create a new list element with NULL content"},
		{int_content, "Create a new list element with dynamically allocated integer content"},
		{(void*)str_content2, "Create a new list element with static string content"},
	};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	i;

	printf("\n\033[4mTesting ft_lstnew :\033[0m\n\n");

	// Iterate through test cases
	for (i = 0; i < num_tests; i++)
	{
		t_list	*result;

		// Call ft_lstnew with the current content
		result = ft_lstnew(tests[i].content);

		// Print test case information
		printf("\033[4mTest %d:\033[0m\n", i + 1);
		printf("Description: %s\n", tests[i].description);

		// Print content appropriately
		if (tests[i].content == int_content)
			printf("Content: Integer %d\n", *(int *)(tests[i].content));
		else if (tests[i].content == NULL)
			printf("Content: NULL\n");
		else
			printf("Content: %s\n", (char *)tests[i].content);

		printf("Expected Result: Non-NULL pointer with content matching input and next == NULL\n");
		printf("Actual Result: %s\n", result ? "Non-NULL pointer" : "NULL");

		// Check if the result is not NULL
		if (result != NULL)
		{
			// Check if content matches and next is NULL
			if (result->content == tests[i].content && result->next == NULL)
				printf("Result: \033[32mPASS\033[0m\n");
			else
				printf("Result: \033[31mFAIL\033[0m - Content or next pointer mismatch\n");
		}
		else
			printf("Result: \033[31mFAIL\033[0m - ft_lstnew returned NULL\n");

		// Free the allocated list element
		free(result);

		printf("---------------------------\n");
	}

	// Free allocated contents
	free(int_content);
	free(str_content);

	return 0;
}

