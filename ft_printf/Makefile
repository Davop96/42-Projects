NAME = libftprint.a

LIBFT_DIR	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LFLAGS		= -L$(LIBFT_DIR) -lft
AR 			= ar rcs
RM 			= rm -f

FILES 		= 	ft_conversion.c \
				ft_convert_c.c \
				ft_convert_d_i.c \
				ft_convert_p.c \
				ft_convert_pct.c \
				ft_convert_s.c \
				ft_convert_ux.c \
				ft_initialize.c \
				ft_parse.c \
				ft_placeholder.c \
				ft_printf.c

FILES_BONUS = 

SRCS_DIR 	= ./
SRCS 		= $(addprefix $(SRCS_DIR), $(FILES))
SRCS_BONUS 	= $(addprefix $(SRCS_DIR), $(FILES_BONUS))

OBJ_DIR 	= ./

OBJ 		= $(SRCS:%.c=%.o)
OBJ_BONUS 	= $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): 	$(OBJ) $(LIBFT)
			$(AR) $(NAME) $(OBJ)

%.c: %.o
			$(CC) -c $(CFLAGS) -c $< -o $@

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

bonus: 		$(OBJ_BONUS)
			$(AR) $(NAME) $(OBJ_BONUS)

clean:
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			$(RM) $(NAME)

re: 		clean all

rebonus: 	fclean bonus

.PHONY: 	all bonus clean fclean re rebonus