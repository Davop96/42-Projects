/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:54:20 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 14:42:52 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Loads the north wall texture from its path.
static int	cb_init_north_texture(t_texture *textures)
{
	if (textures->north_path == NULL
		|| cb_load_texture(&textures->north, textures->north_path) == 1)
		return (1);
	return (0);
}

// Loads the south wall texture from its path.
static int	cb_init_south_texture(t_texture *textures)
{
	if (textures->south_path == NULL
		|| cb_load_texture(&textures->south, textures->south_path) == 1)
	{
		if (textures->north)
		{
			mlx_delete_texture(textures->north);
			textures->north = NULL;
		}
		return (1);
	}
	return (0);
}

// Loads the west wall texture from its path.
static int	cb_init_west_texture(t_texture *textures)
{
	if (textures->west_path == NULL
		|| cb_load_texture(&textures->west, textures->west_path) == 1)
	{
		if (textures->north)
		{
			mlx_delete_texture(textures->north);
			textures->north = NULL;
		}
		if (textures->south)
		{
			mlx_delete_texture(textures->south);
			textures->south = NULL;
		}
		return (1);
	}
	return (0);
}

// Loads the east wall texture from its path.
static int	cb_init_east_texture(t_texture *textures)
{
	if (textures->east_path == NULL
		|| cb_load_texture(&textures->east, textures->east_path) == 1)
	{
		if (textures->north)
		{
			mlx_delete_texture(textures->north);
			textures->north = NULL;
		}
		if (textures->south)
		{
			mlx_delete_texture(textures->south);
			textures->south = NULL;
		}
		if (textures->west)
		{
			mlx_delete_texture(textures->west);
			textures->west = NULL;
		}
		return (1);
	}
	return (0);
}

// Initializes all wall textures (north, south, west, east).
int	cb_init_textures(t_texture *textures)
{
	if (cb_init_north_texture(textures) == 1)
		return (1);
	if (cb_init_south_texture(textures) == 1)
		return (1);
	if (cb_init_west_texture(textures) == 1)
		return (1);
	if (cb_init_east_texture(textures) == 1)
		return (1);
	return (0);
}
