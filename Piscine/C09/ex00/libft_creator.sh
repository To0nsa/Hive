# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 10:50:54 by nlouis            #+#    #+#              #
#    Updated: 2024/09/19 12:58:03 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME="libft.a"

SRC_FILES="ft_putchar.c ft_putstr.c ft_swap.c ft_strlen.c ft_strcmp.c"

echo "Compiling source files..."
cc -Wall -Wextra -Werror -c $SRC_FILES

echo "Creating the library $LIB_NAME..."
ar rcs "$LIB_NAME" *.o

echo "Cleaning up object files..."
rm -f *.o

echo "Library $LIB_NAME created successfully."