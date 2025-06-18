NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

SRC_DIR			= ./src
OBJ_DIR			= ./obj
INC_DIR			= ./include
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBFT_INC		= -I $(LIBFT_DIR)/include

SRC_FILES		=  $(SRC_DIR)/builtins/minishell_builtin_manager.c $(SRC_DIR)/builtins/minishell_builtins_cd_1.c \
					$(SRC_DIR)/builtins/minishell_builtins_echo.c $(SRC_DIR)/builtins/minishell_builtins_export_1.c \
					$(SRC_DIR)/builtins/minishell_builtins_export_2.c $(SRC_DIR)/builtins/minishell_builtins_unset.c \
					$(SRC_DIR)/builtins/minishell_others_builtins.c $(SRC_DIR)/executer/main.c \
					$(SRC_DIR)/executer/minishell_commands.c $(SRC_DIR)/executer/minishell_execution_1.c \
					$(SRC_DIR)/executer/minishell_execution_2.c $(SRC_DIR)/executer/minishell_fork.c \
					$(SRC_DIR)/executer/minishell_heredoc_1.c $(SRC_DIR)/executer/minishell_paths.c \
					$(SRC_DIR)/executer/minishell_redirections_1.c $(SRC_DIR)/executer/minishell_redirections_2.c \
					$(SRC_DIR)/executer/minishell_variables_to_array.c $(SRC_DIR)/expander/minishell_env_variables_copy.c \
					$(SRC_DIR)/expander/minishell_env_variables_dollar_1.c $(SRC_DIR)/expander/minishell_env_variables_expand_1.c \
					$(SRC_DIR)/expander/minishell_env_variables_expand_2.c $(SRC_DIR)/expander/minishell_env_variables_length.c \
					$(SRC_DIR)/expander/minishell_exit_status.c $(SRC_DIR)/expander/minishell_handle_dollars_1.c \
					$(SRC_DIR)/expander/minishell_handle_dollars_2.c $(SRC_DIR)/parser/minishell_automata.c \
					$(SRC_DIR)/parser/minishell_errors.c $(SRC_DIR)/parser/minishell_parser_errors.c \
					$(SRC_DIR)/parser/minishell_parser.c $(SRC_DIR)/signals/minishell_signals_1.c \
					$(SRC_DIR)/tokenizer/minishell_token_creator.c $(SRC_DIR)/tokenizer/minishell_token_handler.c \
					$(SRC_DIR)/tokenizer/minishell_token_quotes_1.c $(SRC_DIR)/tokenizer/minishell_tokenizer.c \
					$(SRC_DIR)/utils/minishell_utils_1.c $(SRC_DIR)/utils/minishell_utils_2.c \
					$(SRC_DIR)/utils/minishell_utils_3.c $(SRC_DIR)/executer/minishell_pipes_1.c \
					$(SRC_DIR)/builtins/minishell_builtin_exit.c $(SRC_DIR)/expander/minishell_env_variables_dollar_2.c \
					$(SRC_DIR)/tokenizer/minishell_token_collector.c $(SRC_DIR)/tokenizer/minishell_token_quotes_2.c \
					$(SRC_DIR)/executer/minishell_redirections_3.c $(SRC_DIR)/executer/minishell_pipes_2.c \
					$(SRC_DIR)/executer/minishell_pipes_3.c $(SRC_DIR)/executer/minishell_pipes_4.c \
					$(SRC_DIR)/builtins/minishell_builtins_cd_2.c $(SRC_DIR)/executer/minishell_execution_3.c \
					$(SRC_DIR)/executer/minishell_heredoc_2.c $(SRC_DIR)/signals/minishell_signals_2.c
					
					 
OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# COLORES
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_INC) -c $< -o $@

$(NAME): libft $(OBJS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -lreadline
	@printf "${CYAN}Program ready!${RESET}\n"

$(LIBFT):
	@printf "${YELLOW}Building libft.a...${RESET}\n"
	@$(MAKE) -C $(LIBFT_DIR) all -s

all: $(NAME)

libft: $(LIBFT)
	@printf "${YELLOW}Compiling libft...${RESET}\n"
	@$(MAKE) -C $(LIBFT_DIR) -s

clean:
	@printf "${YELLOW}Cleaning object files.${RESET}\n"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@printf "${CYAN}Object files cleaned.${RESET}\n"

fclean: clean
	@printf "${YELLOW}Removing executable and libft.a.${RESET}\n"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@printf "${CYAN}Executable and libft cleaned.${RESET}\n"

re: fclean all

.SILENT: all clean fclean re $(NAME) BANNER

BANNER:
	@printf "${BLUE}\n-----------------------------------------------------------------------------------\n${RESET}\n"
	@printf "${YELLOW}\n\t\t      Program created by dbohoyo- & dvacas-h ${RESET}\n"
	@printf "\n"
	@printf "  ██████   ██████  ███              ███          █████               ████  ████  \n"
	@printf " ░░██████ ██████  ░░░              ░░░          ░░███               ░░███ ░░███  \n"
	@printf "  ░███░█████░███  ████  ████████   ████   █████  ░███████    ██████  ░███  ░███  \n"
	@printf "  ░███░░███ ░███ ░░███ ░░███░░███ ░░███  ███░░   ░███░░███  ███░░███ ░███  ░███  \n"
	@printf "  ░███ ░░░  ░███  ░███  ░███ ░███  ░███ ░░█████  ░███ ░███ ░███████  ░███  ░███  \n"
	@printf "  ░███      ░███  ░███  ░███ ░███  ░███  ░░░░███ ░███ ░███ ░███░░░   ░███  ░███  \n"
	@printf "  █████     █████ █████ ████ █████ █████ ██████  ████ █████░░██████  █████ █████ \n"
	@printf " ░░░░░     ░░░░░ ░░░░░ ░░░░ ░░░░░ ░░░░░ ░░░░░░  ░░░░ ░░░░░  ░░░░░░  ░░░░░ ░░░░░  \n"
	@printf "\n"
	@printf "${BLUE}-------------------------------------------------------------------------------------\n${RESET}\n"


.PHONY: all clean fclean re libft

