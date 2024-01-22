# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:33:37 by scrumier          #+#    #+#              #
#    Updated: 2024/01/11 16:45:42 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
       ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
       ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
       ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
       ft_bzero.c ft_isascii.c ft_memcpy.c ft_memmove.c \
       ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
       ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
       ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
       ft_strtrim.c ft_striteri.c ft_atoi.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) libft.h
    ar rc $(NAME) $(OBJS)

%.o: %.c libft.h
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(RM) $(OBJS)

fclean: clean
    $(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
