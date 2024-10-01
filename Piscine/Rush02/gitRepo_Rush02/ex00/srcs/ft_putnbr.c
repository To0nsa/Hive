/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:23:57 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/21 19:58:21 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;
	int		divisor;
	char	digit;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		digit = (n / divisor) + '0';
		ft_putchar(digit);
		n %= divisor;
		divisor /= 10;
	}
}
