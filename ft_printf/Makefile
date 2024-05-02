# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 14:46:08 by dbohoyo-          #+#    #+#              #
#    Updated: 2024/04/30 14:58:32 by dbohoyo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar rcs
RM 			= rm -f

FILES 		= 	ft_conversion.c \
				ft_printf.c \
				ft_tools.c \
				ft_vprintf.c 
				
OBJ_DIR 	= ./

OBJS 		= $(FILES:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re