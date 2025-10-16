NAME			= cub3d
BONUS_NAME		= cub3d_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

SRC_DIR			= ./src
BONUS_DIR		= ./bonus
OBJ_DIR			= ./obj
INC_DIR			= ./include
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBFT_INC		= -I $(LIBFT_DIR)/include

MLX42_DIR		= ./MLX42
MLX42			= $(MLX42_DIR)/build/libmlx42.a
MLX42_INC		= -I $(MLX42_DIR)/include

SRC_FILES		= $(SRC_DIR)/cub3d_parse_1.c $(SRC_DIR)/cub3d_textures_1.c $(SRC_DIR)/cub3d_keys.c $(SRC_DIR)/cub3d_utils.c \
					$(SRC_DIR)/cub3d_colors_1.c $(SRC_DIR)/cub3d_casting_1.c $(SRC_DIR)/cub3d_casting_2.c $(SRC_DIR)/cub3d_moves_1.c \
					$(SRC_DIR)/cub3d_moves_2.c $(SRC_DIR)/cub3d_reading.c $(SRC_DIR)/cub3d_map_1.c $(SRC_DIR)/cub3d_map_2.c \
					$(SRC_DIR)/cub3d_map_3.c $(SRC_DIR)/cub3d_map_4.c $(SRC_DIR)/cub3d.c $(SRC_DIR)/cub3d_parse_map_1.c \
					$(SRC_DIR)/cub3d_parse_map_2.c $(SRC_DIR)/cub3d_colors_2.c $(SRC_DIR)/cub3d_parse_2.c $(SRC_DIR)/cub3d_parse_3.c \
					$(SRC_DIR)/cub3d_textures_2.c $(SRC_DIR)/cub3d_parse_4.c

BONUS_FILES = $(BONUS_DIR)/cub3d_parse_1_bonus.c $(BONUS_DIR)/cub3d_textures_1_bonus.c $(BONUS_DIR)/cub3d_keys_bonus.c $(BONUS_DIR)/cub3d_weapon_1_bonus.c \
					$(BONUS_DIR)/cub3d_colors_1_bonus.c $(BONUS_DIR)/cub3d_casting_1_bonus.c $(BONUS_DIR)/cub3d_casting_2_bonus.c $(BONUS_DIR)/cub3d_moves_1_bonus.c \
					$(BONUS_DIR)/cub3d_moves_2_bonus.c $(BONUS_DIR)/cub3d_reading_bonus.c $(BONUS_DIR)/cub3d_map_1_bonus.c  $(BONUS_DIR)/cub3d_map_2_bonus.c \
					$(BONUS_DIR)/cub3d_map_3_bonus.c $(BONUS_DIR)/cub3d_map_4_bonus.c $(BONUS_DIR)/cub3d_bonus.c $(BONUS_DIR)/cub3d_utils_bonus.c \
					$(BONUS_DIR)/cub3d_parse_map_1_bonus.c $(BONUS_DIR)/cub3d_parse_map_2_bonus.c $(BONUS_DIR)/cub3d_weapon_2_bonus.c $(BONUS_DIR)/cub3d_colors_2_bonus.c \
					$(BONUS_DIR)/cub3d_parse_2_bonus.c $(BONUS_DIR)/cub3d_parse_3_bonus.c $(BONUS_DIR)/cub3d_parse_4_bonus.c $(BONUS_DIR)/cub3d_textures_2_bonus.c

OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS		= $(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

# COLORES
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_INC) $(MLX42_INC) -c $< -o $@

$(OBJ_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c $(INC_DIR)/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_INC) $(MLX42_INC) -c $< -o $@

$(NAME): libft mlx42 $(OBJS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lm -lpthread -lX11 -lreadline
	@printf "${CYAN}Program ready!${RESET}\n"

$(LIBFT):
	@printf "${YELLOW}Building libft.a...${RESET}\n"
	@$(MAKE) -C $(LIBFT_DIR) all -s

$(MLX42):
	@printf "${YELLOW}Building MLX42...${RESET}\n"
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build -s

all: $(NAME)

libft: $(LIBFT)
	@printf "${YELLOW}Compiling libft...${RESET}\n"
	@$(MAKE) -C $(LIBFT_DIR) -s

mlx42: $(MLX42)
	@printf "${YELLOW}Compiling MLX42...${RESET}\n"
	@$(MAKE) -C $(MLX42_DIR)/build -s

bonus: libft mlx42 $(BONUS_OBJS)
	@$(MAKE) BANNER -s
	@printf "${YELLOW}Files read.${RESET}\n"
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L $(LIBFT_DIR) -lft -L $(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lm -lpthread -lX11 -lreadline
	@printf "${CYAN}Bonus program ready!${RESET}\n"

clean:
	@printf "${YELLOW}Cleaning object files.${RESET}\n"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@if [ -d "$(MLX42_DIR)/build" ]; then $(MAKE) -C $(MLX42_DIR)/build clean -s; fi
	@printf "${CYAN}Object files cleaned.${RESET}\n"

fclean: clean
	@printf "${YELLOW}Removing executable and libft.a.${RESET}\n"
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@if [ -d "$(MLX42_DIR)/build" ]; then $(RM) -r $(MLX42_DIR)/build; fi
	@printf "${CYAN}Executable, libft, and MLX42 cleaned.${RESET}\n"

re: fclean all

.SILENT: all clean fclean re $(NAME) BANNER

BANNER:
	@printf "${BLUE}\n-----------------------------------------------------------------------------------\n${RESET}\n"
	@printf "${YELLOW}\n\t\t      Program created by dbohoyo- & dvacas-h ${RESET}\n"
	@printf "\n"
	@printf "________/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\________/\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\___/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____\n"
	@printf " _____/\\\\\\\\\\\\////////__\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\/////////\\\\\\\\\\\\___/\\\\\\\\\\\\///////\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\////////\\\\\\\\\\\\__\n"
	@printf "  ___/\\\\\\\\\\\\/___________\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\__\\\\///______/\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\______\\\\//\\\\\\\\\\\\_\n"
	@printf "   __/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__________/\\\\\\\\\\\\//___\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\n"
	@printf "    _\\\\/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\/////////\\\\\\\\\\\\________\\\\////\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\n"
	@printf "     _\\\\//\\\\\\\\\\\\____________\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\___________\\\\//\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\n"
	@printf "      __\\\\///\\\\\\\\\\\\__________\\\\//\\\\\\\\\\\\______/\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\__/\\\\\\\\\\\\______/\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\_______/\\\\\\\\\\\\__\n"
	@printf "       ____\\\\////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/__\\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\n"
	@printf "        _______\\\\/////////_____\\\\/////////_____\\\\/////////////______\\\\/////////_____\\\\////////////_____\n"
	@printf "\n"
	@printf "${BLUE}-------------------------------------------------------------------------------------\n${RESET}\n"

.PHONY: all clean fclean re libft mlx42

