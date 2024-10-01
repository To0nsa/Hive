/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:46:48 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 19:41:46 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

void	ft_dict_free(t_NumberWord *parsed_d, int count_entries)
{
	int	i;

	i = 0;
	while (i < count_entries)
	{
		free(parsed_d[i].number);
		free(parsed_d[i].word);
		i++;
	}
	free(parsed_d);
}
