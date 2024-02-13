# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 11:47:40 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/02/08 14:28:52 by sonamcrumie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	mlx-linux/
SRC_PATH	=	src/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), gnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	cc
CFLAGS		=	-Wall -Wextra
RM			=	rm -f
SRCS		=	fdf.c parse_input.c
OBJS		=	$(SRCS:$(SRC_PATH)%.c=%.o)

all:			$(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
	$(CC) $(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_A): FORCE
				@$(MAKE) -s -C $(LIBFT)

$(GNL_A): FORCE
				@$(MAKE) -s -C $(GNL)

$(MLX_A): FORCE
				@$(MAKE) -s -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:			@$(RM) $(OBJS)
				@$(MAKE) clean -s -C $(LIBFT)
				@$(MAKE) clean -s -C $(GNL)
				@$(MAKE) clean -s -C $(MLX)

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@$(MAKE) fclean -s -C $(GNL)
				@$(MAKE) clean -s -C $(MLX)
				@$(RM) $(NAME)

re:				fclean all

FORCE:


.PHONY:			all clean fclean re 
