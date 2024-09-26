/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:38:00 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:38:01 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(){
	char s1[] = "CProgramming";
	char s2[] = "Hive School";
	char s3[] = "Alibaba";
	char s4[] = "";
	char s5[] = "CProgramming";
	char s6[] = "CProgramming rocks !";

	unsigned int n = 4;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", ft_strncmp(s1, s3, n));
	printf("%d\n", ft_strncmp(s1, s4, n));
	printf("%d\n", ft_strncmp(s1, s5, n));
	printf("%d\n", ft_strncmp(s1, s6, n));
	printf("%d\n", ft_strncmp(s4, s1, n));
	return (0);
} */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 && *s2 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if ((*s1 || *s2) && n--)
		return (*s1 - *s2);
	return (0);
}
