#all, clean, fclean, re, bonus

NAME = my_printf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_PATH = printf.h

SRC_NAME_TWO = is_libft.c is_insert_flag.c is_put.c is_error.c is_create.c is_parse.c printf.c main.c

SRC_NAME = is_flag.c is_libft.c is_insert_flag.c printf.c main.c is_execute.c

OBJ_NAME = $(SRC_NAME_TWO:.c=.o)

all: $(NAME)

%.o: %.c $(INC_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_NAME)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
		@rm -rf $(NAME)

re: fclean all bonus

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake: printf.o
#	$(CC) -o hellomake printf.o
