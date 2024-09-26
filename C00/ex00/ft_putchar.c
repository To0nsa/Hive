/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:50:07 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/20 12:31:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* void	ft_putchar(char c);

int	main(void)
{
	char	c;

	c = '1';
	ft_putchar(&c);
	return (0);
} */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
