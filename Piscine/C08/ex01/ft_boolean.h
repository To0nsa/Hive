/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:50:53 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/24 09:45:03 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H

# include <stdbool.h>
# include <unistd.h>

# define SUCCESS 0
# define TRUE 1
# define FALSE 0

typedef bool	t_bool;

# define EVEN(nbr) ((nbr) % 2 == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

void				ft_putstr(char *str);
t_bool				ft_is_even(int nbr);

#endif