# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = a.out
SRC = src/main.c src/arg_validation.c src/init_list.c src/threads_proces.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lm -o $(NAME)


clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus