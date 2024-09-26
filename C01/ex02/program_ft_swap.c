/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_ft_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:55:35 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 18:29:58 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

void ft_swap(int *a, int *b);

int main()
{
	int a;
	int b;

	a = 42;
	b = 84;
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
} */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
