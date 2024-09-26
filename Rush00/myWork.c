#include <unistd.h>

void	top_bottom_line(int x);
void	middle_line(int y, int x);
void	ft_putchar(char c);

int	main() {
	top_bottom_line(15);
	middle_line(10, 15);
	top_bottom_line(15);
	ft_putchar('\n');
	return 0;
}

void	top_bottom_line(int x)
{
	int	line_nbr_x;

	line_nbr_x = 0;
	while (line_nbr_x <= x)
	{ 
		if (line_nbr_x == 0 || line_nbr_x == x)
			ft_putchar('o');
		else
			ft_putchar('-');
		line_nbr_x++;
	}
	ft_putchar('\n');
}

void	middle_line(int y, int x)
{
	int	line_nbr_x;
	int line_nbr_y;

	line_nbr_y = 0;
	while (line_nbr_y < y - 2)
	{
		line_nbr_x = 0;
		while (line_nbr_x < x)   
		{
			if (line_nbr_x == 0 || line_nbr_x == x +1)  
				ft_putchar('|');
			else
				ft_putchar(' ');  
			line_nbr_x++;
		}
		ft_putchar('\n');
		line_nbr_y++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}