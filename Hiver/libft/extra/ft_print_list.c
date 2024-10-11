
#include <libft.h>

void ft_print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}