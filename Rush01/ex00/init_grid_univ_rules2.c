/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid_univ_rules2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:31:36 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/15 22:33:49 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	if_clue_is_one(int **clues, int **grid, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (clues[0][i] == 1)
			grid[0][i] = grid_size;
		if (clues[1][i] == 1)
			grid[grid_size - 1][i] = grid_size;
		if (clues[2][i] == 1)
			grid[i][0] = grid_size;
		if (clues[3][i] == 1)
			grid[i][grid_size - 1] = grid_size;
		i++;
	}
}

void	if_clue_is_four(int **clues, int **grid, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (clues[0][i] == grid_size)
			grid[0][i] = 1;
		if (clues[1][i] == grid_size)
			grid[grid_size - 1][i] = 1;
		if (clues[2][i] == grid_size)
			grid[i][0] = 1;
		if (clues[3][i] == grid_size)
			grid[i][grid_size - 1] = 1;
		i++;
	}
}
