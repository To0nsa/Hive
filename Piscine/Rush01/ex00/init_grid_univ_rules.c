/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid_univ_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:50:41 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/15 23:24:57 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	if_clue_is_one(int **clues, int **grid, int grid_size);
void	if_clue_is_four(int **clues, int **grid, int grid_size);

void	if_clue_four_ordsize_top(int **clues, int **grid, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		if (clues[0][i] == grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[j][i] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	if_clue_four_ordsize_bottom(int **clues, int **grid, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		if (clues[1][i] == grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[grid_size - 1 - j][i] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	if_clue_four_ordsize_left(int **clues, int **grid, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		if (clues[2][i] == grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[i][j] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	if_clue_four_ordsize_right(int **clues, int **grid, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		if (clues[3][i] == grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[i][grid_size - 1 - j] = j + 1;
				j++;
			}
		}
		i++;
	}
}

int	**init_grid_univ_rules(int **clues, int **grid, int grid_size)
{
	if_clue_is_one(clues, grid, grid_size);
	if_clue_is_four(clues, grid, grid_size);
	if_clue_four_ordsize_top(clues, grid, grid_size);
	if_clue_four_ordsize_bottom(clues, grid, grid_size);
	if_clue_four_ordsize_left(clues, grid, grid_size);
	if_clue_four_ordsize_right(clues, grid, grid_size);
	return (grid);
}
