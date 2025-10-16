/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:05:40 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/09 14:27:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	read_next_line(int fd, t_state *state, char *line)
{
	int	i;

	i = 0;
	while (1)
	{
		if (state->buffer_pos >= state->buffer_read)
		{
			state->buffer_read = read(fd, state->buffer, BUFFER_SIZE);
			state->buffer_pos = 0;
			if (state->buffer_read <= 0)
				break ;
		}
		line[i] = state->buffer[state->buffer_pos];
		i++;
		if (state->buffer[(state->buffer_pos)++] == '\n')
			break ;
	}
	line[i] = '\0';
	return (i);
}

char	*get_next_line(int fd)
{
	static t_state	state = {{0}, 0, 0};
	char			line[70000];
	int				len;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = read_next_line(fd, &state, line);
	if (len == 0)
		return (NULL);
	result = ft_strdup(line);
	return (result);
}
