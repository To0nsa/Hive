/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberhanu <eberhanu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:19:05 by eberhanu          #+#    #+#             */
/*   Updated: 2024/09/08 14:19:11 by eberhanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	draw(int x, char a, char b, char c)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
			ft_putchar(a);
		else
		{
			if (j < (x - 1))
				ft_putchar(b);
			else
				ft_putchar(c);
		}
		j++;
	}
	ft_putchar('\n');
}

void	rush00(int x, int y)
{
	int	i;

	i = 0;
	if ((x <= 0) || (y <= 0) || (x > 2147483647) || (y > 2147483647))
	{
		write(1, "ERROR! INPUT MUST BE AN INT BETWEEN 1 & 2147483647\n", 51);
		return ;
	}
	while (i < y)
	{
		if (i == 0)
			draw(x, 'o', '-', 'o');
		else if (i == y - 1)
			draw(x, 'o', '-', 'o');
		else if (i > 0 && i < y - 1)
			draw(x, '|', ' ', '|');
		i++;
	}
}
