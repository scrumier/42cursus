# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 23:46:53 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/02/06 11:38:01 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_DIR = src/
SRC_1 = instructions1.c instructions2.c instructions3.c main.c radix.c \
		sort2-5.c sort2-5_bis.c utils.c t_list.c index.c check_args.c free_stack.c

OBJ_1 = $(addprefix $(OBJ_DIR), $(SRC_1:.c=.o))

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)/includes
LIBFT_LINK = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJ_1) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_1) -o $(NAME) $(LIBFT_LINK)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_1)
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

debug: $(NAME)
	lldb ./$(NAME)
