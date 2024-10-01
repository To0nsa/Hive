/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:17:28 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 18:30:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main() {
	int div;
	int mod;

	ft_div_mod(10, 3, &div, &mod);	
	printf("%d\n", div);
	printf("%d\n", mod);
	return(0);
} */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
