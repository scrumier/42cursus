# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:32:51 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/01/17 19:04:20 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = push_swap.c argv_checker.c dup_sort_checker.c put_index.c \
        instructions.c sort.c utils.c input_processing.c ft_split.c \
        find_best_way.c

OBJ_1 = $(addprefix $(OBJ_DIR), $(SRC_1:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(DEBUG_FLAGS) -c $< -o $@

$(NAME): $(OBJ_1)
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(OBJ_1) -o $(NAME)

clean:
	$(RM) $(OBJ_1)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

debug: $(NAME)
	lldb ./$(NAME)
	
leaks: $(NAME)
	leaks ./$(NAME)

