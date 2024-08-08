/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:59:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/08 16:35:21 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_x(t_map *lst)
{
	int	x;

	x = 0;
	while (lst->map[x] != '\n')
		x++;
	return (x);
}

int	map_size_y(t_map *lst)
{
	int	y;

	y = 0;
	while (lst)
	{
		y++;
		lst = lst->next;
	}
	return (y);
}

char	**make_matrix(t_game *game)
{
	char	**matrix;
	t_map	*temp;
	int		i;

	i = 0;
	temp = game->map;
	matrix = malloc(sizeof(char *) * (game->size.y + 1));
	if (!matrix)
		return (NULL);
	while (game->map)
	{
		matrix[i] = ft_strdup(game->map->map);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
		game->map = game->map->next;
	}
	game->map = temp;
	matrix[i] = NULL;
	return (matrix);
}

void	process_map_line(t_game *game, char *map_line)
{
	t_map	*new_line;

	if (map_line[0] == '\n')
	{
		ft_printf("Error: Invalid map - empty line detected.\n");
		free(map_line);
		exit(EXIT_FAILURE);
	}
	new_line = list_map_line(map_line);
	map_add_back(game, new_line);
	free(map_line);
}

t_map	*make_map(t_game *game)
{
	char	*map_line;
	int		fd;

	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Map not found or without permission.\n");
		return (NULL);
	}
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		process_map_line(game, map_line);
		map_line = get_next_line(fd);
	}
	close(fd);
	return (game->map);
}
