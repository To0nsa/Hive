/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:17:58 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/23 11:43:25 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(){
	int min;
	int max;
	int	*range;
	int size;

	min = 5;
	max = 15;
	size = ft_ultimate_range(&range, min, max);
	printf("%d\n", size);	
	if (range != NULL)
		free(range);
	return (0);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*temp;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	temp = *range;
	while (min < max)
		*temp++ = min++;
	return (size);
}
