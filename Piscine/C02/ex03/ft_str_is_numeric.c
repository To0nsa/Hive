/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:51:01 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:15:01 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int ft_str_is_numeric(char *str);

int main(){
	char str[] = "42";
	char str1[] = "42 84";
	char str2[] = "";
	char str3[] = "42-84";

	printf("%s\n", str);
	ft_str_is_numeric(str);
	printf("Test case 1: %s -> %d\n", str, ft_str_is_numeric(str));
	printf("Test case 2: %s -> %d\n", str1, ft_str_is_numeric(str1));
	printf("Test case 3: %s -> %d\n", str2, ft_str_is_numeric(str2));
	printf("Test case 4: %s -> %d\n", str3, ft_str_is_numeric(str3));
	return (0);
} */

int	ft_str_is_numeric(char	*str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9')))
			return (0);
		str++;
	}
	return (1);
}
