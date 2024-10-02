/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:07:55 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 22:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

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

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*substr;
	size_t			str_len;
	size_t			max_len;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	substr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strncpy(substr, str + start, max_len);
	substr[max_len] = '\0';
	return (substr);
}
