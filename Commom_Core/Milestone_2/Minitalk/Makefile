
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRC = client.c
SERVER_SRC = server.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CLIENT = client
SERVER = server
CLIENT_BONUS_SRC = bonus/client_bonus.c
SERVER_BONUS_SRC = bonus/server_bonus.c
CLIENT_BONUS = client_b
SERVER_BONUS = server_b

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) -L$(LIBFT_PATH) -lft

$(SERVER): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRC) -L$(LIBFT_PATH) -lft

$(SERVER_BONUS): $(SERVER_BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRC) -L$(LIBFT_PATH) -lft

clean:
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
