/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:52:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 16:12:49 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Check that the map does not have any prohibited characters.
int	cb_validate_allowed_chars(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
				&& c != 'W' && c != ' ' && c != 'L')
			{
				printf("Error: allowed characters: 'N', 'S', 'E', 'W'."
					" There must be only 1 player.\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Auxiliary function called in cb_validate_no_open_spaces
int	cb_is_open_to_outside(t_map *map, int y, int x)
{
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
	{
		printf("Error: open space at the edge of the map.\n");
		return (1);
	}
	if (map->grid[y - 1][x] == ' ' || map->grid[y + 1][x] == ' '
		|| map->grid[y][x - 1] == ' ' || map->grid[y][x + 1] == ' ')
	{
		printf("Error: open space connected to the outside.\n");
		return (1);
	}
	return (0);
}

// Check that there are no open holes connected to the outside.
int	cb_validate_no_open_spaces(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '0' || map->grid[y][x] == 'N'
				|| map->grid[y][x] == 'S' || map->grid[y][x] == 'E'
				|| map->grid[y][x] == 'W')
			{
				if (cb_is_open_to_outside(map, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Main function that groups all map validations.
int	cb_validate_map_all(t_map *map)
{
	if (cb_validate_map_borders(map)
		|| cb_validate_player_count(map)
		|| cb_validate_no_empty_lines(map)
		|| cb_validate_allowed_chars(map)
		|| cb_validate_no_open_spaces(map))
	{
		printf("Error: invalid map.\n");
		return (1);
	}
	return (0);
}
