/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:17:24 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:23:38 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int ft_str_is_printable(char *str);

int main(){
	char str[] = "programmingŒ ?";
	char str1[] = "HIVE School";
	char str2[] = "";
	char str3[] = "P!SCiNE";

	printf("%s\n", str);
	ft_str_is_printable(str);
	printf("Test case 1: %s -> %d\n", str, ft_str_is_printable(str));
	printf("Test case 2: %s -> %d\n", str1, ft_str_is_printable(str1));
	printf("Test case 3: %s -> %d\n", str2, ft_str_is_printable(str2));
	printf("Test case 4: %s -> %d\n", str3, ft_str_is_printable(str3));
	return (0);
} */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str > 31 && *str < 127))
			return (0);
		str++;
	}
	return (1);
}
