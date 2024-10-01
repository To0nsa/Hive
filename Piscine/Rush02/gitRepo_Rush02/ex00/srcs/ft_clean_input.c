/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:25:20 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 23:02:21 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

char	*ft_skip_signs(char *str, int *count_sign)
{
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			(*count_sign)++;
		str++;
	}
	return (str);
}

char	*ft_skip_whitespace_argv(char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_clean_input(char *argv1, char *input)
{
	int			count_sign;
	int			mod;
	int			i;
	char		*str;

	count_sign = 0;
	mod = 0;
	i = 0;
	str = ft_skip_whitespace_argv(argv1);
	str = ft_skip_signs(str, &count_sign);
	mod = count_sign % 2;
	if (mod != 0)
		return (NULL);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 0)
		return (NULL);
	input = malloc(i + 1);
	if (!input)
		return (NULL);
	input = ft_strncpy(input, str, i);
	input[i] = '\0';
	return (input);
}
