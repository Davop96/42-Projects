/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_casting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:49:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:12:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Casts a single ray for the given screen column.
void	cb_cast_ray(t_cub3d *cub, int screen_x, t_ray *ray)
{
	ray->pos_x = cub->player.pos_x;
	ray->pos_y = cub->player.pos_y;
	cb_calc_ray_dir(cub, &ray->dir_x, &ray->dir_y, screen_x);
	cb_setup_dda(cub, ray->dir_x, ray->dir_y, ray);
	cb_init_step_x(cub, ray);
	cb_init_step_y(cub, ray);
	cb_perform_dda(cub, ray);
	cb_calc_wall_dist(ray);
}

// Calculates the direction of the ray for a given screen column.
void	cb_calc_ray_dir(t_cub3d *cub, double *ray_dir_x,
	double *ray_dir_y, int screen_x)
{
	double	camera_x;

	camera_x = 2 * screen_x / (double)WIDTH - 1;
	*ray_dir_x = cub->player.dir_x + cub->player.plane_x * camera_x;
	*ray_dir_y = cub->player.dir_y + cub->player.plane_y * camera_x;
}

// Sets up DDA algorithm parameters for the current ray.
void	cb_setup_dda(t_cub3d *cub, double ray_dir_x,
	double ray_dir_y, t_ray *ray)
{
	ray->map_x = (int)cub->player.pos_x;
	ray->map_y = (int)cub->player.pos_y;
	if (ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray_dir_y);
}

// Initializes the step and initial side distance for the X direction.
void	cb_init_step_x(t_cub3d *cub, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.pos_x)
			* ray->delta_dist_x;
	}
}

// Initializes the step and initial side distance for the Y direction.
void	cb_init_step_y(t_cub3d *cub, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.pos_y)
			* ray->delta_dist_y;
	}
}
