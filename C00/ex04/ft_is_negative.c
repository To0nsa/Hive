/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:21:45 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 17:39:49 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* void	ft_is_negative(int n);

int	main(void)
{
	ft_is_negative(10);
	write(1, '\n', 1);
	return (0);
} */

void	ft_is_negative(int n)
{
	char N;
	char P;

	N = 'N';
	P = 'P';
	if (n < 0)
		write(1, &N, 1);
	else
		write(1, &P, 1);
}
