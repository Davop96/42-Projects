/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_colors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:14:43 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/09/25 16:15:14 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw the ceiling and floor on the screen using the colors stored in `cub`.
void	cb_draw_floor_ceiling(t_cub3d *cub)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(cub->game_img, x, y, cub->ceiling_color);
			y++;
		}
		while (y < HEIGHT)
		{
			mlx_put_pixel(cub->game_img, x, y, cub->floor_color);
			y++;
		}
		x++;
	}
}

uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y)
{
	int		idx;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	idx = (y * tex->width + x) * 4;
	r = tex->pixels[idx + 0];
	g = tex->pixels[idx + 1];
	b = tex->pixels[idx + 2];
	a = tex->pixels[idx + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
