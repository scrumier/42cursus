# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:25:42 by scrumier          #+#    #+#              #
#    Updated: 2024/01/31 22:16:00 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	mlx_linux/
SRC_PATH	=	
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), gnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	cc
CFLAGS		=	-Wall -Wextra
RM			=	rm -f
SRCS		=	src/main.c

OBJS		=	$(SRCS:%.c=%.o)

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


.PHONY:			all clean fclean re localclean bonus
