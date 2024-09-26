/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:46:40 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 20:40:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int	ft_sqrt(int nb);

int	main() {
	printf("%d\n", ft_sqrt(9));
	return(0);
}
 */
int	ft_sqrt(int nb)
{
	int sq;

	sq = 1;
	if(nb == 0)
		return(0);
	while (sq * sq < nb)
	{
		sq++;
	}
	if ((nb % sq) == 0)
		return (sq);
	else
		return(0);
}