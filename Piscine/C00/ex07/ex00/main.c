/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:24:19 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/21 10:28:20 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rush-02.h>

int	main(int argc, char *argv[])
{	
	long long input;
	
	if (argc == 1 || argc > 3)
	{
		ft_putstr(ERR_MSG);
		return (FAIL);	
	}		
	if (argc == 3)
		input = ft_atoi(argv[2]);
	else if (argc == 2)
		input = ft_atoi(argv[1]);	
	if (input < 0)
	{
		ft_putstr(ERR_MSG);
		return (FAIL);
	}
	return (SUCCESS);
}