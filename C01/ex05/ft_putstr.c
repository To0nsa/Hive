/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:44:41 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 18:31:38 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* void ft_putstr(char *str);

int main (){
	char *str;

	str = "C Programming!\n";
	ft_putstr(str); 
	return 0;
} */

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

/* void	ft_putstr(char *str)
{
	if (*str)
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

void	ft_putstr(char *str) 
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
} */

/* void	ft_putstr(char *str)
{
	int	len;

	if (str == NULL)
		return ;
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}
 */