/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:50:43 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/09/22 13:17:25 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check that the vertical edges of the map are bordered by walls or spaces.
int	cb_validate_map_borders_vertical(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' && map->grid[y][0] != ' ')
		{
			printf("Error: The map can only be bordered by walls or spaces.\n");
			return (1);
		}
		if (map->grid[y][map->width - 1] != '1'
			&& map->grid[y][map->width - 1] != ' ')
		{
			printf("Error: The map can only be bordered by walls or spaces.\n");
			return (1);
		}
		y++;
	}
	return (0);
}

// Check that the horizontal edges of the map are bordered by walls or spaces.
int	cb_validate_map_borders_horizontal(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' && map->grid[0][x] != ' ')
		{
			printf("Error: The map can only be bordered by walls or spaces.\n");
			return (1);
		}
		if (map->grid[map->height - 1][x] != '1'
			&& map->grid[map->height - 1][x] != ' ')
		{
			printf("Error: The map can only be bordered by walls or spaces.\n");
			return (1);
		}
		x++;
	}
	return (0);
}

// Main border validation function
int	cb_validate_map_borders(t_map *map)
{
	if (cb_validate_map_borders_vertical(map))
		return (1);
	if (cb_validate_map_borders_horizontal(map))
		return (1);
	return (0);
}

// Check that there is only one player and that he is in a valid position.
int	cb_validate_player_count(t_map *map)
{
	int	y;
	int	x;
	int	player_count;

	player_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		printf("Error: allowed characters: 'N', 'S', 'E', 'W'."
			" There must be only 1 player.\n");
		return (1);
	}
	return (0);
}

// Check that there are no empty lines within the map.
int	cb_validate_no_empty_lines(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] == '\0')
		{
			printf("Error: empty line in .cub file\n");
			return (1);
		}
		y++;
	}
	return (0);
}
