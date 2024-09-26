# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:44:23 by nlouis            #+#    #+#              #
#    Updated: 2024/09/22 22:22:49 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC_DIR = srcs

SRC = $(SRC_DIR)/ft_clean_input.c \
	$(SRC_DIR)/ft_putstr.c \
	$(SRC_DIR)/ft_putnbr.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_strstrs.c \
	$(SRC_DIR)/ft_dict_free.c \
	$(SRC_DIR)/ft_extract_entry.c \
	$(SRC_DIR)/ft_dict_handling.c \
	$(SRC_DIR)/ft_skip_whitespace.c \
	$(SRC_DIR)/ft_clean_input.c \
	$(SRC_DIR)/ft_strcpy.c \
	$(SRC_DIR)/ft_argc_two.c \
	$(SRC_DIR)/ft_strncpy.c \
	$(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strcat.c \
	$(SRC_DIR)/main.c 

OBJ = $(SRC:.c=.o)

LIB = librush02.a
NAME = rush-02

all: $(NAME)

$(LIB): $(OBJ)
	@ar rcs $(LIB) $(OBJ)

$(NAME): $(LIB) $(SRC_DIR)/main.o
	$(CC) $(CFLAGS) $(SRC_DIR)/main.o -L. -lrush02 -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c includes/rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re