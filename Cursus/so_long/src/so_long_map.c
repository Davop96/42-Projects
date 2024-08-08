/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:01 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/08 16:35:54 by dbohoyo-         ###   ########.fr       */
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

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = ft_strdup(map_line);
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
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
