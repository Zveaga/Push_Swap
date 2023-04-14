NAME = push_swap

SRC = \
push_swap_utils.c \
push_swap.c \
push.c \
radix.c \
reverse_rotate.c \
rotate.c \
set_index.c \
simple_sort.c \
swap.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(LIBFT_A) $(OBJ) -o $(NAME)

$(LIBFT_A):
	make -C libft

%.o: %.c | $(LIBFT_A)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c -o $@ $^

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re