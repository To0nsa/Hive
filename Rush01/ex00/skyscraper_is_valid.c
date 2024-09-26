/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:58:19 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/15 23:28:38 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_top_bottom(int **clues, int **grid, int grid_size)
{
	int	col;
	int	row;
	int	max_height_seen;
	int	visible_count;

	col = 0;
	while (col < grid_size)
	{
		row = 0;
		max_height_seen = 0;
		visible_count = 0;
		while (row < grid_size)
		{
			if (grid[row][col] > max_height_seen)
			{
				visible_count++;
				max_height_seen = grid[row][col];
			}
			row++;
		}
		if (visible_count != clues[0][col])
			return (0);
		col++;
	}
	return (1);
}

int	check_bottom_top(int **clues, int **grid, int grid_size)
{
	int	col;
	int	row;
	int	max_height_seen;
	int	visible_count;

	col = 0;
	while (col < grid_size)
	{
		row = grid_size - 1;
		max_height_seen = 0;
		visible_count = 0;
		while (row >= 0)
		{
			if (grid[row][col] > max_height_seen)
			{
				visible_count++;
				max_height_seen = grid[row][col];
			}
			row--;
		}
		if (visible_count != clues[1][col])
			return (0);
		col++;
	}
	return (1);
}

int	check_left_right(int **clues, int **grid, int grid_size)
{
	int	row;
	int	col;
	int	max_height_seen;
	int	visible_count;

	row = 0;
	while (row < grid_size)
	{
		col = 0;
		max_height_seen = 0;
		visible_count = 0;
		while (col < grid_size)
		{
			if (grid[row][col] > max_height_seen)
			{
				visible_count++;
				max_height_seen = grid[row][col];
			}
			col++;
		}
		if (visible_count != clues[2][row])
			return (0);
		row++;
	}
	return (1);
}

int	check_right_left(int **clues, int **grid, int grid_size)
{
	int	row;
	int	col;
	int	max_height_seen;
	int	visible_count;

	row = 0;
	while (row < grid_size)
	{
		col = grid_size - 1;
		max_height_seen = 0;
		visible_count = 0;
		while (col >= 0)
		{
			if (grid[row][col] > max_height_seen)
			{
				visible_count++;
				max_height_seen = grid[row][col];
			}
			col--;
		}
		if (visible_count != clues[3][row])
			return (0);
		row++;
	}
	return (1);
}

int	check_skyscraper_is_valid(int **clues, int **grid, int grid_size)
{
	if (!check_top_bottom(clues, grid, grid_size))
		return (0);
	if (!check_bottom_top(clues, grid, grid_size))
		return (0);
	if (!check_left_right(clues, grid, grid_size))
		return (0);
	if (!check_right_left(clues, grid, grid_size))
		return (0);
	return (1);
}
