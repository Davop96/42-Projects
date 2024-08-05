# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/08/05 19:52:45 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= so_long

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLX42			= ./MLX42
LIBFT			= ./libft
RM 				= rm -f

SRC_DIR			= ./src
OBJ_DIR			= ./obj

SRC_FILES		= 	$(SRC_DIR)/main.c $(SRC_DIR)/so_long_utils.c \
					$(SRC_DIR)/so_long_map.c $(SRC_DIR)/so_long_map_utils.c \
					$(SRC_DIR)/so_long_verifier.c $(SRC_DIR)/so_long_initializer.c \
					$(SRC_DIR)/so_long_player.c $(SRC_DIR)/so_long_assets.c \
					$(SRC_DIR)/so_long_memory.c $(SRC_DIR)/so_long_moves.c

OBJS			= 	$(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES 		= -I$(MLX42)/include -I$(LIBFT)/include
LIBS 			= -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)


all: $(NAME)

clean:
			$(MAKE) -C $(LIBFT) clean
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(MAKE) -C $(LIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re