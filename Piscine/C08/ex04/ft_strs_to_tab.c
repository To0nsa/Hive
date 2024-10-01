/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:42:24 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/24 17:02:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		src_length;

	src_length = ft_strlen(src);
	copy = malloc(src_length + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < src_length)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_par_free(struct s_stock_str *par, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (par[i].copy)
			free(par[i].copy);
		i++;
	}
	free(par);
}

int	ft_fill_stock_str(t_stock_str *array, int j, char *src)
{
	array[j].size = ft_strlen(src);
	array[j].str = src;
	array[j].copy = ft_strdup(src);
	if (array[j].copy == NULL)
		return (0);
	return (1);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;
	int			j;

	array = malloc(ac * sizeof(t_stock_str));
	if (!array)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!ft_fill_stock_str(array, j, av[i]))
		{
			ft_par_free(array, j);
			return (NULL);
		}
		i++;
		j++;
	}
	array[j].str = NULL;
	array[j].copy = NULL;
	return (array);
}
