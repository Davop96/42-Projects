# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 14:46:08 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/12/02 15:45:35 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj

SRC_FILES = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c \
			$(SRC_DIR)/ft_split.c $(SRC_DIR)/ft_strjoin.c \
			$(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_substr.c \
			$(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strdup.c \
			$(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/ft_lstadd_back.c $(SRC_DIR)/ft_lstnew.c

OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.SILENT: all clean $(NAME)

all: $(NAME)

clean:
		$(RM) -r $(OBJ_DIR)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
