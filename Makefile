SERVER_NAME = server

CLIENT_NAME = client

CC_FLAGS = -Wall -Wextra -Werror -g3

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

SERVER_SRC = server.c

CLIENT_SRC = client.c

LIBS = -Lft_printf -lftprintf -Llibft -lft

PRINTF = ./ft_printf/libftprintf.a

LIBFT = ./libft/libft.a

all: server client

server: $(PRINTF) $(LIBFT) $(SERVER_OBJ) 
	$(CC) $(CC_FLAGS) $(SERVER_OBJ) $(LIBS) -o $(SERVER_NAME)

client: $(PRINTF) $(LIBFT) $(CLIENT_OBJ) 
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ) $(LIBS) -o $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -I. -I./includes/ -O3 -c $< -o $@

$(PRINTF):
	@make -C ft_printf

$(LIBFT):
	@make -C libft

clean:
	@make -C ft_printf clean
	@make -C libft clean
	rm -rf $(SERVER_OBJ)
	rm -rf $(CLIENT_OBJ)

fclean: clean
	@make -C ft_printf fclean
	@make -C libft fclean
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re client server