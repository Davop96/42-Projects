/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:48 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/14 12:02:09 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *left_str, char *buff);
char				*ft_read_left_str(int fd, char *left_str);
char				*ft_get_line(char *left_str);
char				*ft_new_left_str(char *left_str);
size_t				ft_strlen(char *s);

#endif