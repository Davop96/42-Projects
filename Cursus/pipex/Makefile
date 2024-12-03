# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:08:02 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/11/28 17:05:02 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
NAME_BONUS		= pipex_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT			= ./libft
RM				= rm -f

SRC_DIR			= ./src
OBJ_DIR			= ./obj
BONUS_DIR		= ./bonus

SRC_FILES		= $(SRC_DIR)/pipex.c $(SRC_DIR)/pipex_utils.c \
				$(SRC_DIR)/pipex_memory.c $(SRC_DIR)/pipex_checker.c
				
BONUS_FILES		= $(BONUS_DIR)/pipex_bonus.c $(BONUS_DIR)/pipex_utils_bonus.c \
				$(BONUS_DIR)/pipex_memory_bonus.c $(BONUS_DIR)/pipex_checker_bonus.c \
				$(BONUS_DIR)/pipex_here_doc.c $(BONUS_DIR)/pipex_open_fd.c

OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS		= $(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

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

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(OBJS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@printf "${CYAN}Program ready!${RESET}\n"

$(NAME_BONUS): $(LIBFT)/libft.a $(OBJS_BONUS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBS)
	@printf "${CYAN}Program ready!${RESET}\n"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT) -s

.SILENT: all clean $(NAME) $(NAME_BONUS) BANNER

all: BANNER $(NAME)

bonus: BANNER $(NAME_BONUS)

clean:
	@printf "${YELLOW}Cleaning main files.${RESET}\n"
	@$(MAKE) -C $(LIBFT) clean -s
	@$(RM) -r $(OBJ_DIR)
	@printf "${CYAN}Main files cleaned.${RESET}\n"

fclean: clean
	@printf "${YELLOW}Cleaning libft files.${RESET}\n"
	@$(MAKE) -C $(LIBFT) fclean -s
	@printf "${CYAN}Libft files cleaned.${RESET}\n"
	@$(RM) $(NAME) $(NAME_BONUS)

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
