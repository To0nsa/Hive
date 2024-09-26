 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:14:39 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/20 10:01:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int	size = 3;
	char	*strs[] = {"Hello", "World", "42"};
	char	*sep = ", ";
	char	*strjoin;

	strjoin = ft_strjoin(size, strs, sep);
	if (strjoin == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Joined string: %s\n", strjoin);
	free(strjoin);
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	sep_len;

	total_len = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

int	ft_strcpy(char *dest, char *src, int pos)
{
	int	i;

	i = 0;
	while (src[i])
		dest[pos++] = src[i++];
	return (pos);
}

char	*ft_allocate_memory(int size, char **strs, char *sep)
{
	int				total_len;
	char			*strjoin;

	if (size == 0)
	{
		strjoin = malloc(1);
		if (strjoin != NULL)
			strjoin[0] = '\0';
		return (strjoin);
	}
	total_len = ft_total_length(size, strs, sep);
	strjoin = malloc(total_len + 1);
	if (strjoin == NULL)
		return (NULL);
	return (strjoin);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*strjoin;
	int				i;
	int				pos;

	i = 0;
	pos = 0;
	strjoin = ft_allocate_memory(size, strs, sep);
	while (i < size)
	{
		pos = ft_strcpy(strjoin, strs[i], pos);
		if (i < size - 1)
			pos = ft_strcpy(strjoin, sep, pos);
		i++;
	}
	strjoin[pos] = '\0';
	return (strjoin);
}
