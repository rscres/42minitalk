NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client

B_SERVER_NAME = server_bonus
B_CLIENT_NAME = client_bonus

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -g3

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)

SERVER_SRC = server.c
CLIENT_SRC = client.c

B_SERVER_SRC = ./bonus/server_bonus.c
B_CLIENT_SRC = ./bonus/client_bonus.c

LIBS = -Lft_printf -lftprintf -Llibft -lft

PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

all: $(PRINTF) $(LIBFT)  $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(PRINTF) $(LIBFT) $(B_SERVER_NAME) $(B_CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) 
	$(CC) $(CC_FLAGS) $(SERVER_OBJ) $(LIBS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ) $(LIBS) -o $(CLIENT_NAME)

$(B_SERVER_NAME): $(B_SERVER_OBJ) 
	$(CC) $(CC_FLAGS) $(B_SERVER_OBJ) $(LIBS) -o $(B_SERVER_NAME)

$(B_CLIENT_NAME): $(B_CLIENT_OBJ)
	$(CC) $(CC_FLAGS) $(B_CLIENT_OBJ) $(LIBS) -o $(B_CLIENT_NAME)

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
	rm -rf $(B_SERVER_OBJ)
	rm -rf $(B_CLIENT_OBJ)

fclean: clean
	@make -C ft_printf fclean
	@make -C libft fclean
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)
	rm -rf $(B_SERVER_NAME)
	rm -rf $(B_CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus