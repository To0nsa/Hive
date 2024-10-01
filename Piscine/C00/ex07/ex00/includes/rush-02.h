/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:50:53 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/21 13:04:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H

# define FT_RUSH02_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAIL 1
# define BUFFER_SIZE 1024

# define EVEN(nbr) ((nbr) % 2 == 0)

typedef struct {
	int number;
	char *word;
}	NumberWord;

# define ERR_MSG "Error\n"

int				ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_str_is_alpha(char	*str);
int				ft_str_is_numeric(char	*str);
int				ft_str_is_printable(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strstr(char *str, char *to_find);

#endif