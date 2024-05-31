/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:45:28 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:56 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

char	*get_next_map_line(int fd)
{
	char	*line;

	line = NULL;
	line = get_next_line(fd);
	if (line)
		return (line);
	return (NULL);
}

int	determine_map_dimensions(int fd, int *width, int *height)
{
	char	*line;
	int		line_length;

	*width = 0;
	*height = 0;
	line = get_next_map_line(fd);
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		if (line_length > *width)
			*width = line_length;
		(*height)++;
		free(line);
		line = get_next_map_line(fd);
	}
	close(fd);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	return (*width);
}

void	allocate_rows(char **map, int width, int height, int current_row)
{
	if (current_row < height)
	{
		map[current_row] = malloc((width + 1) * sizeof(char));
		if (!map[current_row])
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		allocate_rows(map, width, height, current_row + 1);
	}
}

char	**allocate_map_memory(int width, int height)
{
	char	**map;

	map = malloc(height * sizeof(char *));
	if (!map)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	allocate_rows(map, width, height, 0);
	return (map);
}


void	free_map_memory(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
