NAME			= ircserv

CC				= c++
INCLUDES		= -I./src/Classes -I./src/Commands -I./src/Messages -I./src/Server
CFLAGS			= -g -Wall -Wextra -Werror -std=c++98 -I$(SRC_DIR) $(INCLUDES)
RM				= rm -f
SRC_DIR			= ./src

CLASSES_DIR		= Classes
COMMANDS_DIR	= Commands
MESSAGES_DIR	= Messages
SERVER_DIR		= Server

CLASSES_SRC		= Channel.cpp Client.cpp
COMMANDS_SRC	= HandleInvite.cpp HandleJoin.cpp HandleKick.cpp HandleMode.cpp HandleNick.cpp \
					HandleNotice.cpp HandlePart.cpp HandlePass.cpp HandlePrivmsg.cpp HandleTopic.cpp \
					HandleUser.cpp Validation.cpp
MESSAGES_SRC	= ClientBuffer.cpp Message.cpp MessageDispatcher.cpp Parser.cpp Tokens.cpp NumRpl.cpp
SERVER_SRC		= Dispatcher.cpp Server.cpp ServerData.cpp

SRC 			= $(addprefix $(SRC_DIR)/, main.cpp) \
					$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES_SRC)) \
					$(addprefix $(SRC_DIR)/$(COMMANDS_DIR)/, $(COMMANDS_SRC)) \
					$(addprefix $(SRC_DIR)/$(MESSAGES_DIR)/, $(MESSAGES_SRC)) \
					$(addprefix $(SRC_DIR)/$(SERVER_DIR)/, $(SERVER_SRC)) \
					$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS_SRC)) \


OBJ_DIR = obj
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

# COLOURS
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
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
	@printf "${YELLOW}\n\t\t Program created by jsanz-bo, dvacas-h & dbohoyo- ${RESET}\n"
	@printf "\n"
	@printf " ███████████ ███████████           █████ ███████████     █████████ \n"
	@printf "░░███░░░░░░█░█░░░███░░░█          ░░███ ░░███░░░░░███   ███░░░░░███\n"
	@printf " ░███   █ ░ ░   ░███  ░            ░███  ░███    ░███  ███     ░░░ \n"
	@printf " ░███████       ░███               ░███  ░██████████  ░███         \n"
	@printf " ░███░░░█       ░███               ░███  ░███░░░░░███ ░███         \n"
	@printf " ░███  ░        ░███               ░███  ░███    ░███ ░░███     ███\n"
	@printf " █████          █████    █████████ █████ █████   █████ ░░█████████ \n"
	@printf "░░░░░          ░░░░░    ░░░░░░░░░ ░░░░░ ░░░░░   ░░░░░   ░░░░░░░░░  \n"
	@printf "\n"
	@printf "\n"
	@printf "${BLUE}\n-------------------------------------------------------------\n${RESET}\n"

.PHONY: all clean fclean re BANNER