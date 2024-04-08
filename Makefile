NAME = libft.a
FILES = ft_isalpha.c \
        ft_isdigit.c
OBJS = $(FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re