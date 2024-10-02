
#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)
#define EOF (-1)

typedef unsigned long long size_t;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif