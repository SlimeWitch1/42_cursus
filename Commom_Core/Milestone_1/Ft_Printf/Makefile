# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: turocha- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 18:55:04 by turocha-          #+#    #+#              #
#    Updated: 2025/08/13 19:41:25 by turocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFTF = ./libft

CC = gcc -Wall -Werror -Wextra

SRC = ft_printf.c ft_logics.c ft_puts.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	${CC} -I. -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTF)
	@cp $(LIBFTF)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@cd $(LIBFTF) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTF) && make fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
