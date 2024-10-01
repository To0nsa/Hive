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

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long size_t;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_par_free(struct s_stock_str *par, int ac);
void	ft_show_tab(struct s_stock_str	*par);
char	*ft_strdup(char *src);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif