/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:06:24 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/15 23:37:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_skyscraper_is_valid(int **clues, int **grid, int grid_size);

int	is_case_empty(int **grid, int row, int col)
{
	if (grid[row][col] == 0)
		return (1);
	else
		return (0);
}

int	find_empty_case(int **grid, int grid_size, int *row, int *col)
{
	*row = 0;
	while (*row < grid_size)
	{
		*col = 0;
		while (*col < grid_size)
		{
			if (is_case_empty(grid, *row, *col))
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

int	is_num_used(int **grid, int size, int pos, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[pos / size][i] == num || grid[i][pos % size] == num)
			return (0);
		i++;
	}
	return (1);
}

int	**solve_grid(int **grid, int grid_size, int **clues)
{
	int	row;
	int	col;
	int	num;

	if (!find_empty_case(grid, grid_size, &row, &col))
	{
		if (check_skyscraper_is_valid(clues, grid, grid_size))
			return (grid);
		else
			return (NULL);
	}
	num = 1;
	while (num <= grid_size)
	{
		if (is_num_used(grid, grid_size, row * grid_size + col, num))
		{
			grid[row][col] = num;
			if (solve_grid(grid, grid_size, clues))
				return (grid);
			grid[row][col] = 0;
		}
		num++;
	}
	return (NULL);
}
