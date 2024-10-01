/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:17:41 by eberhanu          #+#    #+#             */
/*   Updated: 2024/09/09 17:45:35 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	draw(int x, char a, char b, char c) // Parameters :
											//x: The length of the line to be drawn (i.e., how many characters the line will contain).
											// a: The character to be printed at the beginning of the line (the left corner).
											// b: The character to be printed between the start and end (the middle characters).
											// c: The character to be printed at the end of the line (the right corner).
{
	int	j;                                  // j will be used to track the current position in the line as the loop iterates.

	j = 0;                                  // j is initialized to 0 at the start of the function

	while (j < x)                           // The loop will run x times, which means that it will iterate over 
											// all the positions in the line, from 0 to x - 1.
	{
		if (j == 0)                         // When j == 0, it prints the character a. This means the first position 
			ft_putchar(a);					// (leftmost side) in the line will always be the character a.
		else
		{
			if (j < (x - 1))                // When j > 0 and j < x - 1, it prints the character b. This applies to 
				ft_putchar(b);              //all middle positions of the line, between the start and end.
			else
				ft_putchar(c);				// When j == x - 1, it prints the character c. This ensures that the last position 	
		}                                   //(rightmost side) in the line will always be the character c.
		j++;
	}
	ft_putchar('\n');						// incrementation (j++) ensures that the loop moves forward through each position of the line, 
	                                        // allowing the function to print the correct character for each position based on the current  
}											// value of j. This process repeats until the entire line is drawn and j reaches the value of x.

void	rush00(int x, int y)                // x: The width of the rectangle (i.e., how many characters in each row).
                                            // y: The height of the rectangle (i.e., how many rows in total).
{
	int	i;

	i = 0;                                  // The function enters a loop that runs y times, where i is the row number (starting from 0).
											// For each iteration, the draw function is called to print one row of the rectangle.

	/* if ((x <= 0) || (y <= 0) || (x > 2147483647) || (y > 2147483647))
	{
		write(1, "ERROR! INPUT MUST BE AN INT BETWEEN 1 & 2147483647\n", 51);
		return ;
	} */
	while (i < y)
	{
		if (i == 0)
			draw(x, '/', '*', '\\'); // If i is 0 (the first row), it calls draw(x, '/', '*', '\\').
		else if (i == y - 1)
			draw(x, '\\', '*', '/'); // If i == y - 1 (the last row), it calls draw(x, '\\', '*', '/').
		else if (i > 0 && i < y - 1)
			draw(x, '*', ' ', '*'); // For any row that is not the first or last row (i > 0 and i < y - 1), it calls draw(x, '*', ' ', '*')
		
		i++;						// After each row is drawn, i++ increments the row number, and the loop continues until all rows (y rows) are drawn.
	}
}
