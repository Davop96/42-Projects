/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:54:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 16:08:43 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Chooses the correct wall texture based on the ray's side and step direction.
static	mlx_texture_t	*choose_wall_texture(t_cub3d *cub, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (cub->textures.east);
		else
			return (cub->textures.west);
	}
	else
	{
		if (ray->step_y > 0)
			return (cub->textures.south);
		else
			return (cub->textures.north);
	}
}

// Calculates the X coordinate in the wall texture to use.
static int	calc_tex_x(t_cub3d *cub, t_ray *ray, mlx_texture_t *tex,
	double perp_wall_dist)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = cub->player.pos_y + perp_wall_dist * ray->dir_y;
	else
		wall_x = cub->player.pos_x + perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

// Draws the vertical stripe of pixels for the wall using the textures.
static void	draw_stripe_pixels(t_cub3d *cub, t_stripe_params *params)
{
	int	y;
	int	tex_y;

	y = params->draw_start;
	while (y < params->draw_end)
	{
		tex_y = (int)params->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)params->tex->height)
			tex_y = params->tex->height - 1;
		params->tex_pos += params->step;
		mlx_put_pixel(cub->game_img, params->x, y,
			get_texture_pixel(params->tex, params->tex_x, tex_y));
		y++;
	}
}

// Sets up all parameters needed to draw a vertical wall stripe.
static void	setup_stripe_params(t_cub3d *cub, t_ray *ray, int x,
	t_stripe_params *params)
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	mlx_texture_t	*tex;
	int				tex_x;

	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	tex = choose_wall_texture(cub, ray);
	tex_x = calc_tex_x(cub, ray, tex, ray->perp_wall_dist);
	params->tex = tex;
	params->x = x;
	params->draw_start = draw_start;
	params->draw_end = draw_end;
	params->tex_x = tex_x;
	params->step = 1.0 * tex->height / line_height;
	params->tex_pos = (draw_start - HEIGHT / 2 + line_height / 2)
		* params->step;
}

// Draws a single vertical wall stripe at column x using raycasting results.
void	cb_draw_wall_stripe(t_cub3d *cub, t_ray *ray, int x)
{
	t_stripe_params	params;

	setup_stripe_params(cub, ray, x, &params);
	draw_stripe_pixels(cub, &params);
}
