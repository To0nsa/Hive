/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:16:25 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 19:43:47 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>
#include <stdio.h>

int	ft_open_dict(void)
{
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (FAIL);
	}
	return (fd);
}

t_NumberWord	*ft_pars_d(char *buffer, int *count_entries, int bytes_read)
{
	t_NumberWord	*parsed_d;
	char			*ptr;
	char			*number;
	char			*word;

	ptr = buffer;
	parsed_d = malloc(MAX_ENTRIES * sizeof(t_NumberWord));
	if (!parsed_d)
		return (NULL);
	while ((ptr - buffer) < bytes_read)
	{
		ptr = ft_extract_entry(ptr, &number, &word);
		if (ptr == NULL)
		{
			ft_dict_free(parsed_d, *count_entries);
			return (NULL);
		}
		parsed_d[*count_entries].number = number;
		parsed_d[*count_entries].word = word;
		(*count_entries)++;
		ptr = ft_skip_whitespace(ptr);
		if ((ptr - buffer) >= bytes_read || *ptr == '\0')
			break ;
	}
	return (parsed_d);
}

t_NumberWord	*ft_read_dict(int fd, char *buffer, int *count_entries)
{
	int				bytes_read;
	t_NumberWord	*parsed_d;

	parsed_d = NULL;
	*count_entries = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
	{
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	parsed_d = ft_pars_d(buffer, count_entries, bytes_read);
	if (!parsed_d)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (parsed_d);
}

t_NumberWord	*dict_handling(int *count_entries)
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	t_NumberWord	*parsed_d;
	int				i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	parsed_d = NULL;
	fd = ft_open_dict();
	if (fd == FAIL)
		return (NULL);
	parsed_d = ft_read_dict(fd, buffer, count_entries);
	return (parsed_d);
}
