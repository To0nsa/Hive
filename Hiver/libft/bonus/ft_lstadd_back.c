
#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*last;

	if (lst == NULL || new_elem == NULL)
		return ;
	if (*lst == NULL)
		*lst = new_elem;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_elem;
	}
}
