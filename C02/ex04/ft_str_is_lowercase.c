/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:51:01 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:12:39 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int ft_str_is_lowercase(char *str);

int main(){
	char str[] = "programming";
	char str1[] = "HIVE School";
	char str2[] = "";
	char str3[] = "PISCINE";

	printf("%s\n", str);
	ft_str_is_lowercase(str);
	printf("Test case 1: %s -> %d\n", str, ft_str_is_lowercase(str));
	printf("Test case 2: %s -> %d\n", str1, ft_str_is_lowercase(str1));
	printf("Test case 3: %s -> %d\n", str2, ft_str_is_lowercase(str2));
	printf("Test case 4: %s -> %d\n", str3, ft_str_is_lowercase(str3));
	return (0);
}*/

int	ft_str_is_lowercase(char	*str)
{
	while (*str)
	{
		if (!((*str >= 'a') && (*str <= 'z')))
			return (0);
		str++;
	}
	return (1);
}
