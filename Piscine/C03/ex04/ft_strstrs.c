/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:39:16 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 20:08:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* char	*ft_strstr(char *str, char *to_find);

int main(void)
{
    char *str = "Hello, World!";
    char *to_find = "World";
    char *result = ft_strstr(str, to_find);
    
    if (result)
        printf("Found '%s' in '%s' at pos: %td\n", to_find, str, result - str);
    else
        printf("Did not find '%s' in '%s'\n", to_find, str);
    return 0;
} */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

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
