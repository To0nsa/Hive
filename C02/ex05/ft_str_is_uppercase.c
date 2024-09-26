/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_ft_str_is_uppercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:15:38 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:16:32 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int ft_str_is_uppercase(char *str);

int main(){
	char str[] = "programming";
	char str1[] = "HIVE School";
	char str2[] = "";
	char str3[] = "PISCINE";

	printf("%s\n", str);
	ft_str_is_uppercase(str);
	printf("Test case 1: %s -> %d\n", str, ft_str_is_uppercase(str));
	printf("Test case 2: %s -> %d\n", str1, ft_str_is_uppercase(str1));
	printf("Test case 3: %s -> %d\n", str2, ft_str_is_uppercase(str2));
	printf("Test case 4: %s -> %d\n", str3, ft_str_is_uppercase(str3));
	return (0);
} */

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}
