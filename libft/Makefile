NAME = libft.a

SRCMAN = \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_calloc.c \
ft_strdup.c \
ft_itoa.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_free_2d.c \

SRC_BONUS = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \

OBJ_FILES_MAN = $(SRC:.c=.o)

OBJ_FILES_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

ifdef BONUS
OBJ_FILES = $(OBJ_FILES_MAN) $(OBJ_FILES_BONUS)
SRC = $(SRC_BONUS) $(SRCMAN)
else
OBJ_FILES = $(OBJ_FILES_MAN)
SRC = $(SRCMAN)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	@$(MAKE) BONUS=1 all

.PHONY: clean re fclean all bonus