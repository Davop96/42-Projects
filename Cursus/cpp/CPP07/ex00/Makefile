# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/29 11:03:33 by dbohoyo-          #+#    #+#              #
#    Updated: 2026/09/05 18:20:16 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= whatever

CC				= c++
CFLAGS			= -g -Wall -Wextra -Werror -std=c++98
RM				= rm -f
SRC 			= main.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# COLOURS
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(MAKE) BANNER -s
	@echo "${YELLOW}Files read.${RESET}"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "${CYAN}Program ready!${RESET}"

.SILENT: all clean fclean re $(NAME) BANNER

all: $(NAME)

clean:
	@echo "${YELLOW}Cleaning object files.${RESET}"
	@$(RM) -r $(OBJ_DIR)
	@echo "${CYAN}Object files cleaned.${RESET}"

fclean: clean
	@echo "${YELLOW}Removing executable.${RESET}"
	@$(RM) $(NAME)
	@echo "${CYAN}Executable removed.${RESET}"
	

re: fclean all

BANNER:
	@echo "${BLUE}"
	@echo "-------------------------------------------------------------"
	@echo "${RESET}"
	@echo "${YELLOW}"
	@echo "\t\t Program created by: ${RESET}"
	@echo ""
	@echo "▓█████▄  ▄▄▄▄    ▒█████   ██░ ██  ▒█████ ▓██   ██▓ ▒█████"
	@echo "▒██▀ ██▌▓█████▄ ▒██▒  ██▒▓██░ ██▒▒██▒  ██▒▒██  ██▒▒██▒  ██▒"
	@echo "░██   █▌▒██▒ ▄██▒██░  ██▒▒██▀▀██░▒██░  ██▒▒██ ██░▒██░  ██▒"
	@echo "░▓█▄   ▌▒██░█▀  ▒██   ██░░▓█ ░██ ▒██   ██░░▐██▓░▒██   ██░"
	@echo "░▒████▓ ░▓█  ▀█▓░ ████▓▒░░▓█▒░██▓░ ████▓▒░░██▒▓░░ ████▓▒░"
	@echo "▒▒▓  ▒ ░▒▓███▀▒░ ▒░▒░▒░  ▒ ░░▒░▒░ ▒░▒░▒░   ██▒▒▒ ░ ▒░▒░▒░"
	@echo "░ ▒  ▒ ▒░▒   ░   ░ ▒ ▒░  ▒ ░▒░ ░  ░ ▒ ▒░ ▓██ ░▒░   ░ ▒ ▒░"
	@echo "░ ░  ░  ░    ░ ░ ░ ░ ▒   ░  ░░ ░░ ░ ░ ▒  ▒ ▒ ░░  ░ ░ ░ ▒"
	@echo "░     ░          ░ ░   ░  ░  ░    ░ ░  ░ ░         ░ ░"
	@echo "░            ░                           ░ ░"
	@echo ""
	@echo "${BLUE}"
	@echo "-------------------------------------------------------------"
	@echo "${RESET}"

.PHONY: all clean fclean re BANNER