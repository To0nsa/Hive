
#include <libft.h>

void print_list(t_list *lst)
{
    int i = 0;
    while (lst)
    {
        printf("Node %d: %s\n", i, (char *)lst->content);
        lst = lst->next;
        i++;
    }
}