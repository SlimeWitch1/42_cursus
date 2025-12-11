# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: turocha- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 23:52:47 by turocha-          #+#    #+#              #
#    Updated: 2025/10/08 23:52:49 by turocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/error_free.c \
	src/commands/cmd_push.c src/commands/cmd_reverse_rotate.c \
	src/commands/cmd_rotate.c src/commands/cmd_swap.c \
	src/logics/init_push_swap.c src/logics/logics_push_swap.c \
	src/logics/simple_sort.c src/logics/stack_utils.c

OBJ = $(SRC:.c=.o)

all:
	@cd libft && make
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean: 
	@rm -rf $(OBJ)
	@cd ./libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re
