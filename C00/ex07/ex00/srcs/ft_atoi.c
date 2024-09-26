/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:25:20 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/21 11:29:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '+' || str[i] == ' ' || str[i] >= '\t' && str[i] <= '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > LLONG_MAX)
			return (LLONG_MAX);
		if (sign == -1 && - result < LLONG_MIN)
			return (LLONG_MIN);
		i++;
	}
	return ((long long)(sign * result));
}
