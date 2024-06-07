/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:24 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/07 15:54:03 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	populate_map(int fd, char **map, int height)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_map_line(fd);
	while (i < height && line != NULL)
	{
		ft_strcpy(map[i], line);
		free(line);
		i++;
		line = get_next_map_line(fd);
	}
	if (line != NULL)
		free(line);
}
