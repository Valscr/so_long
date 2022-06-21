# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:32:27 by vescaffr          #+#    #+#              #
#    Updated: 2022/06/21 16:58:29 by vescaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c 

OBJS = ${SRCS:.c=.o}


CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -Imlx_linux -O3 -c $< -o $@

$(NAME): ${OBJS}
		$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:	${NAME}

exec:
		${CC} -o prod ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all