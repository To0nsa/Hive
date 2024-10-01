/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:10:37 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:13:27 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(){
	unsigned int n =  7;
	char str1[] = "Helloooo"; 
	char str2[] = "World!";

	printf("source -> %s\n", str1);
	printf("destination -> %s\n", str2);
	ft_strncpy(str2, str1, n);
	printf("%s\n", str2);
	return(0);
} */

char	*ft_strncpy(char	*dest, char	*src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}
