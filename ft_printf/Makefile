# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:59:43 by sonamcrumie       #+#    #+#              #
#    Updated: 2023/12/13 14:49:53 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_print_hex.c ft_print_int.c ft_print_ptr.c \
					ft_print_str.c ft_print_uint.c ft_printf.c
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): 		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
