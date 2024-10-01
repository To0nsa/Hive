/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:32:48 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/20 09:51:26 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h>

int	*ft_range(int min, int max);

int	main(){
	int min;
	int max;
	int	*array;

	min = 10;
	max = 15;
	array = ft_range(min, max);
	if (array == NULL)
		return (1);
	printf("%d\n", array[0]);
	printf("%d\n", array[1]);
	free(array);
	return (0);
} */

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		array[i++] = min++;
	return (array);
}
