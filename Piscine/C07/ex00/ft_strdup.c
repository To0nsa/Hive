/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:45:08 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/24 16:58:46 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h>

char	*ft_strdup(char *src);

int	main(){

	char	*src = "Hello world !";
	char *copy = ft_strdup(src);
	if (copy == NULL)
		return (1);
	printf("%s\n", copy);
	free(copy);
	return (0);
} */

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		src_length;

	src_length = 0;
	while (src[src_length])
		src_length++;
	copy = (char *)malloc((src_length + 1) * sizeof(char));
/* 	if (copy == NULL)
		return (NULL); */
	i = 0;
	while (i < src_length)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
