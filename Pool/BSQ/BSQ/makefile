#Our Makefile for BSQ

#Compile

CC = cc

FLAGS = -Wall -Werror -Wextra

#List of .c files

C_FILES = prueba.c general.c

O_FILES = $(C_FILES:.c=.o)

ADD_FILES = additional files

#executable

NAME = bsq

#rules

$(NAME): $(O_FILES)
		$(CC) $(FLAGS) -o $(NAME) $(O_FILES)

clean:
	rm -f $(NAME) *.o

fclean: clean
	rm -f $(ADD_FILES)


