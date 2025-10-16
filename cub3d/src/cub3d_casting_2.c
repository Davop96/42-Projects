/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_casting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:12:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:15:17 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Performs the DDA algorithm to find the next wall hit by the ray.
void	cb_perform_dda(t_cub3d *cub, t_ray *ray)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		cb_check_map_bounds(cub, ray, &hit);
	}
}

// Calculates the distance from the player to the wall hit by the ray.
void	cb_calc_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

// Checks if the ray is out of map bounds or has hit a wall.
void	cb_check_map_bounds(t_cub3d *cub, t_ray *ray, int *hit)
{
	if (ray->map_x < 0 || ray->map_x >= cub->map.width
		|| ray->map_y < 0 || ray->map_y >= cub->map.height)
	{
		*hit = 1;
		ray->perp_wall_dist = 1e30;
	}
	else if (cub->map.grid[ray->map_y][ray->map_x] == '1')
	{
		*hit = 1;
	}
}
