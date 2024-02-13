# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:25:42 by scrumier          #+#    #+#              #
#    Updated: 2024/02/13 14:11:07 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_NAME      =   libft.a
LIBFT_CC        =   gcc
LIBFT_RM        =   rm -f
GNL             =   get_next_line/
PRINTF          =   ft_printf/
LIBFT_FLAGS     =   -Wall -Wextra -Werror
LIBFT_SRC_DIR   =   libft_src/
GNL_SRC_DIR     =   libft_src/get_next_line/
PRINTF_SRC_DIR  =   libft_src/ft_printf/

LIBFT_SRC = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
			ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
			ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
			ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
			ft_bzero.c ft_isascii.c ft_memcpy.c ft_memmove.c \
			ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
			ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
			ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
			ft_strtrim.c ft_striteri.c ft_atoi.c

GNL_SRC = get_next_line.c get_next_line_utils.c

PRINTF_SRC =	ft_printf.c ft_printf_uint.c ft_printf_str.c \
				ft_printf_ptr.c ft_printf_int.c ft_printf_hex.c

LIBFT_OBJ_DIR = libft_obj/
GNL_OBJ_DIR = gnl_obj/
PRINTF_OBJ_DIR = printf_obj/

LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_SRC:.c=.o))
GNL_OBJ = $(addprefix $(GNL_OBJ_DIR), $(GNL_SRC:.c=.o))
PRINTF_OBJ = $(addprefix $(PRINTF_OBJ_DIR), $(PRINTF_SRC:.c=.o))

LIBFT_INC_DIR = includes/
GNL_INC_DIR = includes/
PRINTF_INC_DIR = includes/

LIBFT_INC = -I$(LIBFT_INC_DIR)
GNL_INC = -I$(GNL_INC_DIR)
PRINTF_INC = -I$(PRINTF_INC_DIR)

all: $(LIBFT_NAME)

$(LIBFT_OBJ_DIR):
	mkdir -p $(LIBFT_OBJ_DIR)

$(GNL_OBJ_DIR):
	mkdir -p $(GNL_OBJ_DIR)

$(PRINTF_OBJ_DIR):
	mkdir -p $(PRINTF_OBJ_DIR)

$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c | $(LIBFT_OBJ_DIR)
	$(LIBFT_CC) $(LIBFT_FLAGS) -c $< -o $@ $(LIBFT_INC)

$(GNL_OBJ_DIR)%.o: $(GNL_SRC_DIR)%.c | $(GNL_OBJ_DIR)
	$(LIBFT_CC) $(LIBFT_FLAGS) -c $< -o $@ $(GNL_INC)

$(PRINTF_OBJ_DIR)%.o: $(PRINTF_SRC_DIR)%.c | $(PRINTF_OBJ_DIR)
	$(LIBFT_CC) $(LIBFT_FLAGS) -c $< -o $@ $(PRINTF_INC)

$(LIBFT_NAME): $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	ar rc $(LIBFT_NAME) $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	ranlib $(LIBFT_NAME)

$(LIBFT_OBJ): | $(LIBFT_OBJ_DIR)
$(GNL_OBJ): | $(GNL_OBJ_DIR)
$(PRINTF_OBJ): | $(PRINTF_OBJ_DIR)

clean:
	$(LIBFT_RM) $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(LIBFT_RM) -r $(LIBFT_OBJ_DIR) $(GNL_OBJ_DIR) $(PRINTF_OBJ_DIR)

fclean: clean
	$(LIBFT_RM) $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
