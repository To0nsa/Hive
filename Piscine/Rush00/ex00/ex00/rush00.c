/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:19:05 by eberhanu          #+#    #+#             */
/*   Updated: 2024/09/08 18:43:04 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
// This is a function prototype for the ft_putchar function, which takes a character as parameter and does not return any value.
void	draw(int x, char a, char b, char c)
// This is a function header for the draw function, which takes an integer x and three characters a, b, and c as parameters.
{
	int	j;
// This is a declaration of the integer variable j
	j = 0;
// This is an assignment statement that initializes the variable j to 0.
	while (j < x)
// This is the beginning of a while loop that will continue to execute as long as the value of j is less than x.
	{
		if (j == 0)
			ft_putchar(a);
// This is the beginning of an "if else" statement, wit an if block that checks if j is equal to 0, and if true, 
// it calls the ft_putchar function to print the character a.
		else
		{
			if (j < (x - 1))
				ft_putchar(b);
			else
				ft_putchar(c);
		}
		j++;
// This is an else block containing an if-else statement. If j is less than x - 1, it calls the ft_putchar function
//  to print the character b. Otherwise, it calls ft_putchar to print the character c. 
// Afterward, the j++ statement increments the value of j by 1.
	}
	ft_putchar('\n');
// This closes the while loop and calls the ft_putchar function to print a newline character ('\n').
}

void	rush00(int x, int y)
// This is a function header for the rush00 function, which takes two integer parameters x and y, and does not return any value.
{
	int	i;

	i = 0;
	if ((x <= 0) || (y <= 0) || (x > 2147483647) || (y > 2147483647))
	{
		write(1, "ERROR! INPUT MUST BE AN INT BETWEEN 1 & 2147483647\n", 51);
		return ;
	}
// This is an if statement that checks whether x or y are less than or equal to 0, or greater than 2,147,483,647 
// (the maximum value for a 32-bit signed integer). If any of these conditions are true, it calls the write function 
// to print an error message and then uses return to exit the function early.
	while (i < y)
	{
		if (i == 0)
			draw(x, 'o', '-', 'o');
		else if (i == y - 1)
			draw(x, 'o', '-', 'o');
		else if (i > 0 && i < y - 1)
			draw(x, '|', ' ', '|');
		i++;
	}
// This is a while loop that continues as long as i is less than y. Inside the loop:
// - If i equals 0, it calls the draw function with x and the characters 'o', '-', and 'o' to draw the top border.
// - If i equals y - 1 (the last row), it also calls draw with the same arguments to draw the bottom border.
// - If i is greater than 0 but less than y - 1, it calls draw with x and the characters '|', ' ', and '|' to draw the sides of the box.
// After each iteration, i++ increments the value of i by 1 to move to the next row.
}
