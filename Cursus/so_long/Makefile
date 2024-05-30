# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/05/30 12:07:29 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLX42			= ./MLX42
PRINTF			= ./ft_printf
GNL     		= ./get_next_line
RM 				= rm -f

SRC_DIR			= src
SRC_FILES		= $(SRC_DIR)/main.c
PRINTF_FILES 	= $(PRINTF)/ft_conversion.c $(PRINTF)/ft_printf.c $(PRINTF)/ft_tools.c $(PRINTF)/ft_vprintf.c
GNL_FILES 		= $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
OBJ_DIR			= obj
OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
				$(PRINTF_FILES:$(PRINTF)/%.c=$(OBJ_DIR)/%.o) \
				$(GNL_FILES:$(GNL)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MLX42) -I$(MLX42)/include -I$(PRINTF) -I$(GNL) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MLX42) -I$(MLX42)/include -I$(PRINTF) -I$(GNL) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MLX42) -I$(MLX42)/include -I$(PRINTF) -I$(GNL) -c $< -o $@	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(MLX42)/include -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread


all: $(NAME)

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re