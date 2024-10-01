/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:27:52 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/19 19:32:15 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int main(void)
{
    char src[] = "Hello, World!";
    char dest[6];

    unsigned int result = ft_strlcpy(dest, src, sizeof(dest));

    printf("Destination: '%s'\n", dest);
    printf("Source Length: %u\n", result);

    if (result >= sizeof(dest))
        printf("Truncation occurred.\n");
    else
        printf("Copy successful without truncation.\n");

    return 0;
} */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
