/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:08:02 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:04:50 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main() {
	char dest[] = "Programming";
	char src[] = "hhhhhhh";

	printf("%s\n", dest);
	printf("%s\n", src);
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	return (0);
} */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
