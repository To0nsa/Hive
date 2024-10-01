/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_ft_recursive_factorial.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:04:10 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 20:37:08 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int	ft_recursive_factorial(int nb);

int main() {
	printf("%d\n", ft_recursive_factorial(3));
	return(0);
} */

int	ft_recursive_factorial(int nb)
{
	if(nb < 0)
		return(0);
	if(nb ==0 || nb == 1)
		return(1);
	return (nb * ft_recursive_factorial(nb - 1));
}
