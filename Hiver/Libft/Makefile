# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I include

# Directories
SRC_DIR = srcs
LIB_DIR = lib
INC_DIR = include

# Library name
NAME    = libft.a

# Source files
SRCS    = ft_atoi.c \
          ft_bzero.c \
          ft_calloc.c \
          ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_itoa.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_memset.c \
          ft_putchar_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c \
          ft_putstr_fd.c \
          ft_split.c \
          ft_strchr.c \
          ft_strdup.c \
          ft_striteri.c \
          ft_strjoin.c \
          ft_strlcat.c \
          ft_strlcpy.c \
          ft_strlen.c \
          ft_strmapi.c \
          ft_strncmp.c \
          ft_strnstr.c \
          ft_strrchr.c \
          ft_strtrim.c \
          ft_substr.c \
          ft_tolower.c \
          ft_toupper.c

# Add the SRC_DIR prefix to source files
SRCS    := $(addprefix $(SRC_DIR)/, $(SRCS))

# Object files will be stored in the LIB_DIR
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(LIB_DIR)/%.o)

# Colors for output
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET   = \033[0m

# Emojis
EMOJI_BUILD = 🛠️
EMOJI_CLEAN = 🧹
EMOJI_OK    = ✅
EMOJI_ERROR = ❌

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

# Default target
all: $(LIB_DIR)/$(NAME)
	@echo "$(GREEN)$(EMOJI_OK)  Build complete!$(RESET)"

# Rule to create the library
$(LIB_DIR)/$(NAME): $(OBJS)
	@echo "$(BLUE)$(EMOJI_BUILD)  Creating $(NAME) library...$(RESET)"
	@ar rcs $@ $^

# Rule to compile object files
$(LIB_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h
	@mkdir -p $(LIB_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(YELLOW)$(EMOJI_CLEAN)  Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

# Clean object files and the library
fclean: clean
	@echo "$(YELLOW)$(EMOJI_CLEAN)  Removing $(NAME) library...$(RESET)"
	@rm -f $(LIB_DIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                 END OF FILE                                  #
# **************************************************************************** #