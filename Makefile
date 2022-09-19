# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 00:42:43 by valentin          #+#    #+#              #
#    Updated: 2022/09/19 13:33:18 by vescaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

C_FILES = so_long.c move_render.c set.c render.c get_next_line.c get_next_line_utils.c \
		check_map.c check_other.c print_img.c set_map.c utils.c render_count.c \
		check_map_valid.c check_map_collect.c check_map_exit.c check_map_utils.c \
		check_map_utils2.c

SRC_DIR		=	./src/

DIR_OBJ = objs/

OBJS = ${C_FILES:%.c=$(DIR_OBJ)%.o}

CFLAGS += -Wall -Wextra -Werror

MLXFLAGS	= -Lmlx_linux -lmlx_Linux -Imlx_linux -L/usr/lib -lXext -lX11 -lm

LIBSFLAGS	=  libft/libft.a ft_printf/libftprintf.a

CC		= gcc
RM		= rm -f

$(NAME): ${OBJS} maker
		@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(MLXFLAGS) $(LIBSFLAGS)
		@echo " [ OK ] So_long is ready"		

$(DIR_OBJ)%.o : $(SRC_DIR)%.c
		@mkdir -p $(DIR_OBJ)
		@$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@
		@echo " [ OK ] "

all: ${NAME}

maker:
		@make -C mlx_linux
		@make -C libft
		@make -C ft_printf

clean:
		@${RM} -rf ${DIR_OBJ}
		@make clean -C libft
		@make clean -C ft_printf

fclean:	clean
		@make clean -C mlx_linux
		@make fclean -C libft
		@make fclean -C ft_printf
		@${RM} ${NAME}

re:		fclean all

norm:
	norminette $(SRC_DIR)*.c includes/so_long.h