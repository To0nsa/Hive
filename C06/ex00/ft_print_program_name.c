/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:48:01 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/20 09:32:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* void	ft_print_program_name(char *program_name);

int	main(int argc, char *argv[])
{
	(void)argc;
	ft_print_program_name(argv[0]);
	return (0);
} */

void	ft_print_program_name(char *program_name)
{
	write(1, program_name, sizeof(program_name));
	write(1, "\n", 1);
}
