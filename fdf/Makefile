# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 13:31:24 by sonam             #+#    #+#              #
#    Updated: 2024/03/12 16:16:04 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Ofast -MMD -MP -g3
LIBRARIES = -Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDES = -I/usr/include -Imlx_linux
SRC_DIR = src
OBJ_DIR = .obj
LIBFT_DIR = libft
NAME = fdf
MLX = mlx_linux
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: mlx libft $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -O3 -c $< -o $@ -I$(LIBFT_DIR)/includes

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBRARIES) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $@

mlx:
	@make -C $(MLX)

libft:
	@make -C $(LIBFT_DIR)

-include $(DEP)

clean:
	$(RM) -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re mlx libft

