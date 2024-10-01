/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:04:23 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/17 12:11:18 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	**allocate_grid(int grid_size)
{
	int	**grid;
	int	row;

	grid = (int **)malloc(grid_size * sizeof(int *));
	if (grid == NULL)
		return (NULL);
	row = 0;
	while (row < grid_size)
	{
		grid[row] = (int *)malloc(grid_size * sizeof(int));
		if (grid[row] == NULL)
		{
			while (row > 0)
			{
				row--;
				free(grid[row]);
			}
			free(grid);
			return (NULL);
		}
		row++;
	}
	return (grid);
}

void	initialize_grid(int **grid, int grid_size)
{
	int	row;
	int	col;

	row = 0;
	while (row < grid_size)
	{
		col = 0;
		while (col < grid_size)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	**create_grid(int grid_size)
{
	int	**grid;

	if (grid_size <= 0)
		return (NULL);
	grid = allocate_grid(grid_size);
	if (grid == NULL)
		return (NULL);
	initialize_grid(grid, grid_size);
	return (grid);
}

void	free_grid(int grid_size, int **grid)
{
	int	row;

	row = 0;
	while (row < grid_size)
	{
		free(grid[row]);
		row++;
	}
	free(grid);
}

int	**print_grid(int **grid, int grid_size)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < grid_size)
	{
		col = 0;
		while (col < grid_size)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < grid_size - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	return (grid);
}
