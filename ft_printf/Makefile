NAME = libftprintf.a

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar rcs
RM 			= rm -f

FILES 		= 	ft_conversion.c \
				ft_pointer.c \
				ft_printf.c \
				ft_tools.c \
				ft_vprintf.c 

SRCS_DIR 	= ./
SRCS 		= $(addprefix $(SRCS_DIR), $(FILES))

OBJ_DIR 	= ./

OBJS 		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(AR) $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re