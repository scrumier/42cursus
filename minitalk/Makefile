# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 23:46:53 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/01/30 09:30:09 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft/libft.a
FTPRINTF	= ./ft_printf/libftprintf.a
RM			= rm -rf

SERVER		= server
CLIENT		= client

SV_SRCS		= src/server.c
SV_OBJS		= $(SV_SRCS:.c=.o)

CLIENT_SRCS	= src/client.c
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)



all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER): $(SV_OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) $(FTPRINTF) -o server

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF) -o client


clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
