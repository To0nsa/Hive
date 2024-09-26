/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:50:53 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 22:22:23 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H

# define RUSH02_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define SUCCESS 0
# define FAIL 1
# define BUFFER_SIZE 1024
# define MAX_ENTRIES 1042

typedef struct s_NumberWord {
	char	*number;
	char	*word;
}	t_NumberWord;

# define ERR_MSG "Error\n"
# define DICT_MSG "Dict Error\n"

void			ft_putstr(char *str);
int				ft_str_is_alpha(char	*str);
int				ft_str_is_numeric(char	*str);
int				ft_str_is_printable(char *str);
int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
char			*ft_strstr(char *str, char *to_find);
t_NumberWord	*dict_handling(int *count_entries);
void			ft_dict_free(t_NumberWord *dictionary, int count_entries);
char			*ft_extract_entry(char *ptr, char **number, char **word);
char			*ft_skip_whitespace(char *ptr);
char			*ft_strcpy(char *dest, char *src);
char			*ft_clean_input(char *argv1, char *input);
char			*ft_skip_signs(char *str, int *count_sign);
char			*ft_argc_two(int argc, char **argv, t_NumberWord *parsed_d);
char			*ft_strncpy(char *dest, const char *src, int n);
int				ft_strcmp(char	*s1, char	*s2);
char			*ft_strcat(char *dest, char *src);

#endif