#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void    ft_rot_13(char *str)
{
    int i = 0;
    char c;

    while (str[i])
    {
        c = str[i];
        if ((c >= 'a' && c <= 'z'))
            c = ((c - 'a' + 1) % 26) + 'a';
        else if ((c >= 'A' && c <= 'Z'))
            c = ((c - 'A' + 1) % 26) + 'A';
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_rot_13(argv[1]);
    write(1, "\n", 1);
    return 0;
}
