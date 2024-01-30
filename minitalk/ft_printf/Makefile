# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:59:43 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/01/29 14:50:58 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_print_hex.c ft_print_int.c ft_print_ptr.c \
				  ft_print_str.c ft_print_uint.c ft_printf.c
OBJS			= $(addprefix obj/, $(SRCS:.c=.o))
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

$(NAME): 		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) -r obj

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
