#Project name
NAME=libftprintf.a
#Compiler
CC=cc
#Compiler flags
CC_FLAGS= -Wall -Werror -Wextra
#Includes
INCLUDES=./ft_printf.h
#Source files
SRC = ft_printf.c num_printers.c handlers.c checkers.c
#Object files
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf libftprintf.a

re: fclean all

norm:
	-@norminette

.PHONY: all clean fclean re norm bonus