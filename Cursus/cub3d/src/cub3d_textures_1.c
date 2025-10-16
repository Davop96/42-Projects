/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:54:49 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 11:55:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Loads a PNG texture from the given file path using MLX42.
int	cb_load_texture(mlx_texture_t **texture, char *path)
{
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		printf("Error: Failed to load texture '%s'.\n", path);
		return (1);
	}
	return (0);
}

// Frees all loaded textures and their associated file path strings.
void	cb_free_textures(t_texture *textures)
{
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->west)
		mlx_delete_texture(textures->west);
	if (textures->east)
		mlx_delete_texture(textures->east);
	if (textures->north_path)
		free(textures->north_path);
	if (textures->south_path)
		free(textures->south_path);
	if (textures->west_path)
		free(textures->west_path);
	if (textures->east_path)
		free(textures->east_path);
}

// Renders the current game frame.
void	cb_render_game(t_cub3d *cub)
{
	int		x;
	t_ray	ray;

	if (!cub->game_img)
	{
		cub->game_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(cub->mlx, cub->game_img, 0, 0);
	}
	cb_draw_floor_ceiling(cub);
	x = 0;
	while (x < WIDTH)
	{
		cb_cast_ray(cub, x, &ray);
		cb_draw_wall_stripe(cub, &ray, x);
		x++;
	}
}
