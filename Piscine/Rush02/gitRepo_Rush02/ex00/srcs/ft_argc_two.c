/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:45 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 22:24:51 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

char	*ft_argc_two(int argc, char **argv, t_NumberWord	*parsed_d)
{
	char	*input;

	input = NULL;
	(void)parsed_d;
	if (argc == 1 || argc > 3)
		return (NULL);
	else if (argc == 2)
		input = ft_clean_input(argv[1], input);
	if (input == NULL)
	{
		ft_putstr(ERR_MSG);
		return (NULL);
	}
	return (input);
}
