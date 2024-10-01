/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:03:07 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:38:25 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(){
	char dest[] = "C Programming ";
	char src[] = "in Hive School !\n";
	unsigned int nb = 5;

	printf("%s", ft_strncat(dest, src, nb));
	return (0);
} */

char	*ft_strncat(char	*dest, char	*src, unsigned int nb)
{
	char	*orig_dest;

	orig_dest = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (orig_dest);
}
