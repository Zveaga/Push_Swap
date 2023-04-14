NAME = push_swap.a

SRC = \
push_swap_utils.c \
push_swap.c \
radix.c \
set_index.c \
push_adri.c \
rotate_adri.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	ar rcs $(NAME) $(OBJ) libft/*.o

libft/libft.a:
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
