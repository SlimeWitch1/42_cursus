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
CFLAGS = -Wall -Werror -Wextra
SRC = ./src/main.c ./src/free.c \
	./src/map_validation/errors.c \
	./src/map_validation/map.c \
	./src/map_validation/matrix.c \
	./src/run_game/game.c \
	./src/run_game/init.c \
	./src/run_game/position.c \
	./src/run_game/render.c

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
