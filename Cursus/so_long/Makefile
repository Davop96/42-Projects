# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/06/04 14:52:51 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLX42			= ./MLX42
LIBFT			= ./libft
RM 				= rm -f

SRC_DIR			= src
SRC_FILES		= 	$(SRC_DIR)/main.c $(SRC_DIR)/so_long_utils.c \
					$(SRC_DIR)/so_long_map.c $(SRC_DIR)/so_long_assets.c \
					$(SRC_DIR)/so_long_parse.c $(SRC_DIR)/so_long_hooks.c \
					$(SRC_DIR)/so_long_initializer.c
OBJ_DIR			= obj
OBJS			= 	$(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES 		= -I$(MLX42)/include -I$(LIBFT)/include
LIBS 			= -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)


all: $(NAME)

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re