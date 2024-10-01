/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clues.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:16:25 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/16 16:42:11 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	is_error_or_wrong(void);

int	**clues_to_2dclues(int grid_size)
{
	int	i;
	int	**clues;

	i = 0;
	clues = (int **)malloc(4 * sizeof(int *));
	if (clues == NULL)
	{
		/* is_error_or_wrong(); */
		return (NULL);
	}
	while (i < 4)
	{
		clues[i] = (int *)malloc(grid_size * sizeof(int));
		if (clues[i] == NULL)
		{
			/* is_error_or_wrong(); */
			return (NULL);
		}
		i++;
	}
	return (clues);
}

int	**parse_clues(char *argv[], int **clues, int grid_size)
{
	int	i;
	int	clue_index;

	i = 0;
	clue_index = 0;
	while (argv[1][i] && clue_index < 4 * grid_size)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '9')
		{
			clues[clue_index / grid_size]
			[clue_index % grid_size] = argv[1][i] - '0';
			clue_index++;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
				i++;
		}
		else
			i++;
	}
	return (clues);
}

void	free_clues(int **clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(clues[i]);
		i++;
	}
	free(clues);
}
