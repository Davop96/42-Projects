# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 19:34:26 by dbohoyo-          #+#    #+#              #
#    Updated: 2025/11/18 16:42:08 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= abstract

CC				= c++
CFLAGS			= -g -Wall -Wextra -Werror -std=c++98
RM				= rm -f
SRC 			= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

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
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@printf "${CYAN}Program ready!${RESET}\n"

.SILENT: all clean fclean re $(NAME) BANNER

all: $(NAME)

clean:
	@printf "${YELLOW}Cleaning object files.${RESET}\n"
	@$(RM) -r $(OBJ_DIR)
	@printf "${CYAN}Object files cleaned.${RESET}\n"

fclean: clean
	@printf "${YELLOW}Removing executable.${RESET}\n"
	@$(RM) $(NAME)
	@printf "${CYAN}Executable removed.${RESET}\n"
	

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

.PHONY: all clean fclean re BANNER
