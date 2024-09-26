/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:35:14 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/17 12:15:27 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	is_error_or_wrong(void);
void	is_input_correct(int argc, char *argv[], int grid_size);
int		**clues_to_2dclues(int grid_size);
int		**parse_clues(char *argv[], int **clues, int grid_size);
int		**create_grid(int grid_size);
int		**init_grid_univ_rules(int **clues, int **grid, int grid_size);
int		**solve_grid(int **grid, int grid_size, int **clues);
int		check_skyscraper_is_valid(int **clues, int **grid, int grid_size);
int		**print_grid(int **grid, int grid_size);
void	free_grid(int grid_size, int **grid);
void	free_clues(int **clues);

int	main(int argc, char *argv[])
{
	int	**grid;
	int	grid_size;
	int	**clues;

	grid_size = 6;
	is_input_correct(argc, argv, grid_size);
	clues = clues_to_2dclues(grid_size);
	clues = parse_clues(argv, clues, grid_size);
	grid = create_grid(grid_size);
	grid = init_grid_univ_rules(clues, grid, grid_size);
	grid = solve_grid(grid, grid_size, clues);
	if (grid)
	{
		print_grid(grid, grid_size);
	}
	else
	{
		is_error_or_wrong();
	}
	free_clues(clues);
	free_grid(grid_size, grid);
	return (0);
}
