/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:25:20 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/25 17:33:32 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
/*#include <stdio.h>

int	main(void)
{
	printf("ft_atoi(\"00000-42a1234\") = %d\n", ft_atoi("00000-42a1234"));
	printf("ft_atoi(\"2147483647\") = %d\n", ft_atoi("2147483647"));
	printf("ft_atoi(\"-2147483648\") = %d\n", ft_atoi("-2147483648"));
	printf("ft_atoi(\"2147483648\") = %d\n", ft_atoi("2147483648"));
	printf("ft_atoi(\"-2147483649\") = %d\n", ft_atoi("-2147483649"));
    return (0);
} */

int	ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

