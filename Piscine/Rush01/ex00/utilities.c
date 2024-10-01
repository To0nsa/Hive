/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:38:05 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/17 12:00:14 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_error_or_wrong(void)
{
	write(1, "Error\n", 6);
}

void	check_digit_and_length(char *input, int x_length, int *digit_count)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] >= '1' && input[i] <= '9')
			(*digit_count)++;
		else if (input[i] != ' ')
		{
			/* is_error_or_wrong(); */
			return ;
		}
		i++;
		if (i > x_length)
		{
			/* is_error_or_wrong(); */
			return ;
		}
	}
}

void	is_input_correct(int argc, char *argv[], int grid_size)
{
	int	digit_count;
	int	expected_digit_count;
	int	x_length;

	digit_count = 0;
	expected_digit_count = grid_size * grid_size;
	(void)expected_digit_count;
	x_length = (grid_size * grid_size) + (grid_size * grid_size - 1);
	if (argc != 2)
	{
		/* is_error_or_wrong(); */
		return ;
	}
	check_digit_and_length(argv[1], x_length, &digit_count);
	/* if (digit_count != expected_digit_count)
		is_error_or_wrong(); */
}
