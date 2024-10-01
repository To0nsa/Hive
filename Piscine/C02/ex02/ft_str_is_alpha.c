/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:51:01 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:14:30 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* int ft_str_is_alpha(char *str);

int main(){
	char str[] = "CProgramming";
	char str1[] = "Hive School";
	char str2[] = "";
	char str3[] = "Piscine42";

	printf("%s\n", str);
	ft_str_is_alpha(str);
	printf("Test case 1: %s -> %d\n", str, ft_str_is_alpha(str));
	printf("Test case 2: %s -> %d\n", str1, ft_str_is_alpha(str1));
	printf("Test case 3: %s -> %d\n", str2, ft_str_is_alpha(str2));
	printf("Test case 4: %s -> %d\n", str3, ft_str_is_alpha(str3));
	return (0);
} */

int	ft_str_is_alpha(char	*str)
{
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);
		str++;
	}
	return (1);
}
