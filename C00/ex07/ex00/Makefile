# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:44:23 by nlouis            #+#    #+#              #
#    Updated: 2024/09/21 09:55:54 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC_DIR = srcs

SRC = $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_str_is_alpha.c 
	$(SRC_DIR)/ft_str_is_numeric.c $(SRC_DIR)/ft_is_printable.c 
	$(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlen.c
	$(SRC_DIR)/ft_strstrs.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

NAME = rush-02.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c includes/rush-02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re