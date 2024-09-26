/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:24:19 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 22:29:22 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

int	main(int argc, char **argv)
{	
	int				count_entries;
	t_NumberWord	*parsed_d;
	char			*input;

	count_entries = 0;
	parsed_d = dict_handling(&count_entries);
	if (!parsed_d || count_entries == 0)
	{
		ft_putstr(DICT_MSG);
		return (FAIL);
	}
	input = ft_argc_two(argc, argv, parsed_d);
	if (input != NULL)
	{
		ft_putstr(input);
		free(input);
	}
	write(1, "\n", 1);
	ft_putstr(parsed_d[1].number);
	write(1, "\n", 1);
	ft_putstr(parsed_d[1].word);
	write(1, "\n", 1);
	ft_dict_free(parsed_d, count_entries);
	return (SUCCESS);
}
