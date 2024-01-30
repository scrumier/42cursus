# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:33:37 by scrumier          #+#    #+#              #
#    Updated: 2024/01/29 14:53:54 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_NAME = libft.a
LIBFT_CC = gcc
LIBFT_RM = rm -f
LIBFT_FLAGS = -Wall -Wextra -Werror
LIBFT_SRC_DIR = libft_src/

LIBFT_SRC = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
            ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
            ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
            ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
            ft_bzero.c ft_isascii.c ft_memcpy.c ft_memmove.c \
            ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
            ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
            ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
            ft_strtrim.c ft_striteri.c ft_atoi.c

LIBFT_OBJ_DIR = libft_obj/
LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_SRC:.c=.o))

LIBFT_INC_DIR = libft_includes/
LIBFT_INC = -I$(LIBFT_INC_DIR)

all: $(LIBFT_NAME)

$(LIBFT_OBJ_DIR):
	mkdir -p $(LIBFT_OBJ_DIR)

$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c | $(LIBFT_OBJ_DIR)
	$(LIBFT_CC) $(LIBFT_FLAGS) -c $< -o $@ $(LIBFT_INC)

$(LIBFT_NAME): $(LIBFT_OBJ)
	ar rc $(LIBFT_NAME) $(LIBFT_OBJ)
	ranlib $(LIBFT_NAME)

$(LIBFT_OBJ): | $(LIBFT_OBJ_DIR)

$(LIBFT_OBJ_DIR):
	mkdir -p $(LIBFT_OBJ_DIR)


clean:
	$(LIBFT_RM) $(LIBFT_OBJ)
	$(LIBFT_RM) -r $(LIBFT_OBJ_DIR)

fclean: clean
	$(LIBFT_RM) $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
