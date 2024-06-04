/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:24 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/04 14:29:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

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
}

char	**read_map(const char *filename, int *width, int *height)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	*width = determine_map_dimensions(fd, width, height);
	map = allocate_map_memory(*width, *height);
	populate_map(fd, map, *height);
	close(fd);
	return (map);
}
