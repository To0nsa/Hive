/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:39:16 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 09:37:45 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		s = str;
		f = to_find;
		while (*s && *f && (*s == *f))
		{
			s++;
			f++;
		}
		if (*f == '\0')
			return (str);
		str++;
	}
	return (NULL);
}
