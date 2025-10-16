/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:25:52 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 10:47:19 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Auxiliar function of cb_pad_map_rows that fills each row.
char	*cb_create_padded_row(char *row_data, int len, int max_width)
{
	char	*new_row;
	int		i;

	new_row = malloc(max_width + 1);
	if (!new_row)
	{
		printf("Error: malloc failed for padding row\n");
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		new_row[i] = row_data[i];
		i++;
	}
	while (i < max_width)
	{
		new_row[i] = ' ';
		i++;
	}
	new_row[max_width] = '\0';
	return (new_row);
}

// Fill the rows of the map with walls to equal their length.
void	cb_pad_map_rows(t_map *map, int max_width)
{
	int		row;
	int		len;
	char	*new_row;

	row = 0;
	while (row < map->height)
	{
		len = ft_strlen(map->grid[row]);
		if (len < max_width)
		{
			new_row = cb_create_padded_row(map->grid[row], len, max_width);
			free(map->grid[row]);
			map->grid[row] = new_row;
		}
		row++;
	}
}

// Opens the map file and returns its descriptor.
int	cb_open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		printf("Error: could not open file %s\n", filename);
	return (fd);
}

// Reserves memory for the map array.
int	cb_prepare_map_grid(t_map *map)
{
	map->grid = malloc(sizeof(char *) * MAX_MAP_HEIGHT);
	if (!map->grid)
		printf("Error: malloc failed for map grid\n");
	return (map->grid != NULL);
}

// Verify that the texture and color paths are present.
int	cb_validate_map_data(t_texture *textures, int color_f_found,
		int color_c_found)
{
	if (!textures->north_path || !textures->south_path
		|| !textures->west_path || !textures->east_path)
	{
		printf("Error: missing texture paths in the .cub file\n");
		return (1);
	}
	if (!color_f_found || !color_c_found)
	{
		printf("Error: floor or ceiling colors are missing in the .cub file\n");
		return (1);
	}
	return (0);
}
