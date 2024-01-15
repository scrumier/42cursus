# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:32:51 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/01/11 14:34:49 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFT = ../libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 =	push_swap.c argv_checker.c dup_sort_checker.c \
		instructions.c sort.c utils.c \

OBJ_1 = $(SRC_1:.c=.o)

INCLUDE = -L ../libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C $(LIBFT)
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}

clean:
	${RM} ${OBJ_1} ${NAME} ${BONUS}
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus
