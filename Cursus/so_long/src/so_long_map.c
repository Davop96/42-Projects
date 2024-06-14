/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:01 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 01:33:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_object	map_objects(t_map *map)
{
	t_object	obj;
	int			i;

	initialize_obj(&obj);
	while (map)
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i] == 'C')
				obj.collec++;
			if (map->map[i] == 'P')
				obj.player++;
			if (map->map[i] == 'E')
				obj.exit++;
			if (map->map[i] == 'X')
				obj.enemy++;
			i++;
		}
		map = map->next;
	}
	return (obj);
}

void	map_add_back(t_game *game, t_map *new)
{
	t_map	*last;

	last = game->map;
	if (!last)
		game->map = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_map	*list_map_line(char *map_line)
{
	t_map	*new;

	new = NULL;
	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	if (new)
	{
		new->map = ft_strdup(map_line);
		new->next = NULL;
	}
	return (new);
}

t_game	*find_player(t_game *game)
{
	int		i;
	int		j;

	j = 1;
	game->player.y = 0;
	game->player.x = 0;
	while (j < game->size.y)
	{
		i = 1;
		while (game->matrix[j][i] != '\n')
		{
			if (game->matrix[j][i] == 'P')
			{
				game->player.y = j;
				game->player.x = i;
				return (game);
			}
			i++;
		}
		j++;
	}
	return (game);
}

t_map	*make_map(t_game *game)
{
	t_map	*new_line;
	char	*map_line;
	int		fd;

	new_line = NULL;
	map_line = NULL;
	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Map not found\n");
		return (new_line);
	}
	map_line = get_next_line(fd);
	if (!map_line)
		return (new_line);
	while (map_line)
	{
		new_line = list_map_line(map_line);
		map_add_back(game, new_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	return (game->map);
}
