# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonam <sonam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 13:31:24 by sonam             #+#    #+#              #
#    Updated: 2024/02/14 13:45:23 by sonam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile variables
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -I/usr/include -Imlx_linux
SRC_DIR = src/
OBJ_DIR = obj/
NAME = fdf

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Main target
all: $(NAME)

# Compilation des fichiers .c en fichiers .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) -O3 -c $< -o $@

# Construction de l'exécutable
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBRARIES) -o $(NAME)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
