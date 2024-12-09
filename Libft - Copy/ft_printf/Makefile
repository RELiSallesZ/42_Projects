# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 15:41:42 by rsalles-          #+#    #+#              #
#    Updated: 2024/01/17 13:54:17 by rsalles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for ft_printf

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror


# Directories
SRC_DIR = source
OBJ_DIR = objects

# Source and object files
SRC_FILES = ft_printf.c ft_printf_utilities.c ft_puthex.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths to source and object files
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# Executable
NAME = libftprintf.a

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule to build the executable
$(NAME): $(OBJ)
	ar rcs $@ $^

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)

# Rule to clean object files and executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and rebuild
re: fclean all

# Rule to build the executable
all: $(NAME)

# Phony targets
.PHONY: all clean fclean re


