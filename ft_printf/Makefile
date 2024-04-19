NAME = libftprint.a

LIBFT_DIR	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a

INCS_DIR	= ./include

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LFLAGS		= -L$(LIBFT_DIR) -lft
AR 			= ar rcs
RM 			= rm -f

FILES 		=

FILES_BONUS = 

SRCS_DIR 	= ./
SRCS 		= $(addprefix $(SRCS_DIR), $(FILES))
SRCS_BONUS 	= $(addprefix $(SRCS_DIR), $(FILES_BONUS))

OBJ_DIR 	= ./

OBJ 		= $(SRCS:%.c=%.o)
OBJ_BONUS 	= $(SRCS_BONUS:%.c=%.o)

%.o: %.c
			$(CC) -c $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ_BONUS)
			$(AR) $(NAME) $(OBJ_BONUS)

clean:
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			$(RM) $(NAME)

re: 		clean all

rebonus: 	fclean bonus

.PHONY: 	all bonus clean fclean re rebonus