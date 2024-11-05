# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/10/25 14:25:58 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT			= ./libft
RM				= rm -f

SRC_DIR			= ./src
OBJ_DIR			= ./obj

SRC_FILES		= $(SRC_DIR)/push_swap.c $(SRC_DIR)/push_swap_index.c \
				$(SRC_DIR)/push_swap_cost.c $(SRC_DIR)/push_swap_cost2.c \
				$(SRC_DIR)/push_swap_instructions.c $(SRC_DIR)/push_swap_instructions2.c \
				$(SRC_DIR)/push_swap_position.c $(SRC_DIR)/push_swap_sort.c \
				$(SRC_DIR)/push_swap_stacks.c $(SRC_DIR)/push_swap_utils.c \
				$(SRC_DIR)/push_swap_checker.c 

OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES		= -I$(LIBFT)/include
LIBS			= -L$(LIBFT) -lft

# COLOURS
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(OBJS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@printf "${CYAN}Program ready!${RESET}\n"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT) -s

.SILENT: all clean $(NAME) BANNER

all: BANNER $(NAME)

clean:
	@printf "${YELLOW}Cleaning main files.${RESET}\n"
	@$(MAKE) -C $(LIBFT) clean -s
	@$(RM) -r $(OBJ_DIR)
	@printf "${CYAN}Main files cleaned.${RESET}\n"

fclean: clean
	@printf "${YELLOW}Cleaning libft files.${RESET}\n"
	@$(MAKE) -C $(LIBFT) fclean -s
	@printf "${CYAN}Libft files cleaned.${RESET}\n"
	@$(RM) $(NAME)

re: fclean all

BANNER:
	@printf "${BLUE}\n-------------------------------------------------------------\n${RESET}\n"
	@printf "${YELLOW}\n\t\t Program created by: ${RESET}\n"
	@printf "\n"
	@printf "▓█████▄  ▄▄▄▄    ▒█████   ██░ ██  ▒█████ ▓██   ██▓ ▒█████  \n"
	@printf "▒██▀ ██▌▓█████▄ ▒██▒  ██▒▓██░ ██▒▒██▒  ██▒▒██  ██▒▒██▒  ██▒\n"
	@printf "░██   █▌▒██▒ ▄██▒██░  ██▒▒██▀▀██░▒██░  ██▒▒██ ██░▒██░  ██▒\n"
	@printf "░▓█▄   ▌▒██░█▀  ▒██   ██░░▓█ ░██ ▒██   ██░░▐██▓░▒██   ██░\n"
	@printf "░▒████▓ ░▓█  ▀█▓░ ████▓▒░░▓█▒░██▓░ ████▓▒░░██▒▓░░ ████▓▒░\n"
	@printf "▒▒▓  ▒ ░▒▓███▀▒░ ▒░▒░▒░  ▒ ░░▒░▒░ ▒░▒░▒░   ██▒▒▒ ░ ▒░▒░▒░\n"
	@printf "░ ▒  ▒ ▒░▒   ░   ░ ▒ ▒░  ▒ ░▒░ ░  ░ ▒ ▒░ ▓██ ░▒░   ░ ▒ ▒░\n"
	@printf "░ ░  ░  ░    ░ ░ ░ ░ ▒   ░  ░░ ░░ ░ ░ ▒  ▒ ▒ ░░  ░ ░ ░ ▒  \n"
	@printf "░     ░          ░ ░   ░  ░  ░    ░ ░  ░ ░         ░ ░  \n"
	@printf "░            ░                           ░ ░              \n\n"
	@printf "${BLUE}\n-------------------------------------------------------------\n${RESET}\n"

.PHONY: all clean fclean re
