# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 14:46:08 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/05/31 15:59:06 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

FILES = ft_conversion.c \
		ft_printf.c \
		ft_tools.c \
		ft_vprintf.c \
		get_next_line.c \
		get_next_line_utils.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

