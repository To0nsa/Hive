/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_ft_strcat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:20:37 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:35:01 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main(){
	char dest[] = "C Programming ";
	char src[] = "in Hive School !\n";

	printf("%s", ft_strcat(dest, src));
	return (0);
} */

char	*ft_strcat(char *dest, char *src)
{
	char	*orig_dest;

	orig_dest = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (orig_dest);
}
