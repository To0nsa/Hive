/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:47:37 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/23 13:52:19 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stock_str
{
int 	size;
char 	*str;
char 	*copy;
} t_stock_str;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_par_free(struct s_stock_str *par, int ac);
void	ft_show_tab(struct s_stock_str	*par);
char	*ft_strdup(char *src);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str	*par);

#endif