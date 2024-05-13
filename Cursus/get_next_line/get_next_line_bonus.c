/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:15 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/10 14:37:25 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
static char	*_set_line(char *line);
static char	*ft_strchr(char *s, int c);

static char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*_set_line(char *line_buffer)
{
	char		*left_c;
	ssize_t		x;

	x = 0;
	while (line_buffer[x] != '\n' && line_buffer[x] != '\0')
		x++;
	if (line_buffer[x] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_c = ft_substr(line_buffer, x + 1, ft_strlen(line_buffer) - x);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[x + 1] = 0;
	return (left_c);
}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

void	read_from_multiple_fds(int fds[], int fd_count)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	while (x < fd_count)
	{
		y = 0;
		while ((line =get_next_line(fds[x] != NULL)))
			free (line);
	}
}

char	*get_next_line(int fd)
{
	static char		*left_c;
	char			*line;
	char			*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}
