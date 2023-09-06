SERVER_NAME = server

CLIENT_NAME = client

CC_FLAGS = -Wall -Wextra -Werror -g3

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

SERVER_SRC = server.c

CLIENT_SRC = client.c

LIBS = -Lft_printf -lftprintf

PRINTF = ./ft_printf/libftprintf.a

all: server client

server: $(PRINTF) $(SERVER_OBJ) 
	$(CC) $(CC_FLAGS) $(SERVER_OBJ) $(LIBS) -o $(SERVER_NAME)

client: $(PRINTF) $(CLIENT_OBJ) 
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ) $(LIBS) -o $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -I. -I./includes/ -O3 -c $< -o $@

$(PRINTF):
	@make -C ft_printf

clean:
	@make -C ft_printf clean
	rm -rf $(SERVER_OBJ)
	rm -rf $(CLIENT_OBJ)

fclean: clean
	@make -C ft_printf fclean
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re client server