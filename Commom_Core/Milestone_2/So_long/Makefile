# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: turocha- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 14:05:27 by turocha-          #+#    #+#              #
#    Updated: 2025/10/14 14:05:31 by turocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = 
SRC = ./src/errors.c ./src/free.c ./src/game.c \
	./src/map.c ./src/matrix.c ./src/position.c ./src/render.c

LIBFT = ./libft/libft.a
NAME = so_long
OBJ = $(SRC:.c=.o)

all: $(LIB)
	cd mlx && make
	cd libft && make
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) ./mlx/libmlx_Linux.a -I./mlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ) 
	cd ./mlx && make clean
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./mlx && make clean
	cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re
