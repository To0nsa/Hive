/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:56:56 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/23 17:12:25 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

char	*ft_extract_number(char *ptr, char **number)
{
	char	*colon;
	char	*trim_spaces;
	int		number_length;

	colon = ft_strstr(ptr, ":");
	if (colon == NULL)
		return (NULL);
	*colon = '\0';
	trim_spaces = colon - 1;
	while (trim_spaces >= ptr && *trim_spaces == ' ')
	{
		*trim_spaces = '\0';
		trim_spaces--;
	}
	number_length = ft_strlen(ptr);
	*number = malloc(number_length + 1);
	if ((*number) == NULL)
		return (NULL);
	ft_strlcpy(*number, ptr, number_length + 1);
	ptr = ft_skip_whitespace(colon + 1);
	return (ptr);
}

char	*ft_extract_word(char *ptr, char **word)
{
	char	*newline;
	int		word_length;

	newline = ft_strstr(ptr, "\n");
	if (newline)
		*newline = '\0';
	word_length = ft_strlen(ptr);
	*word = malloc(word_length + 1);
	if ((*word) == NULL)
		return (NULL);
	ft_strlcpy(*word, ptr, word_length + 1);
	if (newline)
		return (newline + 1);
	return (NULL);
}

char	*ft_extract_entry(char *ptr, char **number, char **word)
{	
	ptr = ft_extract_number(ptr, number);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_extract_word(ptr, word);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
