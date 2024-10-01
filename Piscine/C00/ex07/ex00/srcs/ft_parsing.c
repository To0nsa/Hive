/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:16:25 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/21 13:52:39 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <rush-02.h>

NumberWord *ft_use_dic()
{
	int fd;
	char buffer[BUFFER_SIZE];
	int bytes_read;

	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(ERR_MSG);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (bytes_read == -1)
		{
			ft_putstr(ERR_MSG);
			return (NULL);
		}
		// process the data in the buffer -> parsing
	}
}

NumberWord *ft_use_dic()




