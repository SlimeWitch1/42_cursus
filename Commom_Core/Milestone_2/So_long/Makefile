
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./src/main.c ./src/free.c \
	./src/map_validation/map.c \
	./src/map_validation/matrix.c \
	./src/map_validation/validation.c \
	./src/run_game/game.c \
	./src/run_game/init.c \
	./src/run_game/position.c \
	./src/run_game/render.c

LIBFT = ./libft/libft.a
NAME = so_long
OBJ = $(SRC:.c=.o)

all:
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
