/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:24 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/05 20:02:23 by marvin           ###   ########.fr       */
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

char	**read_map(const char *filename, int *width, int *height)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	*width = determine_map_dimensions(fd, width, height);
	map = allocate_map_memory(*width, *height);
	if (map == NULL)
	{
		perror("Error allocating memory");
		close(fd);
		exit(EXIT_FAILURE);
	}
	populate_map(fd, map, *height);
	close(fd);
	return (map);
}
