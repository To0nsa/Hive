/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:03:53 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 20:38:38 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(){
	printf("%d\n", ft_iterative_power(2, 3));
	return(0);
} */

int	ft_iterative_power(int nb, int power)
{	
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			result =  nb * result;
			power--;
		}
		return (result);
	}
}
