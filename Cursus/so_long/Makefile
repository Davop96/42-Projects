# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/05/31 10:58:41 by dbohoyo-         ###   ########.fr        #
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
SRC_FILES		= $(SRC_DIR)/main.c $(SRC_DIR)/so_long_utils.c $(SRC_DIR)/so_long_assets.c
PRINTF_FILES 	= $(PRINTF)/ft_conversion.c $(PRINTF)/ft_printf.c $(PRINTF)/ft_tools.c $(PRINTF)/ft_vprintf.c
GNL_FILES 		= $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
OBJ_DIR			= obj
OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
				$(PRINTF_FILES:$(PRINTF)/%.c=$(OBJ_DIR)/%.o) \
				$(GNL_FILES:$(GNL)/%.c=$(OBJ_DIR)/%.o)

INCLUDES 		= -I$(MLX42) -I$(MLX42)/include -I$(PRINTF) -I$(GNL)
LIBS 			= -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL)/%.c
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