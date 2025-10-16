/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_moves_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:54:09 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:50:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Rotates the player's view to the left.
void	cb_rotate_left(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(-ROT_SPEED)
		- cub->player.dir_y * sin(-ROT_SPEED);
	cub->player.dir_y = old_dir_x * sin(-ROT_SPEED)
		+ cub->player.dir_y * cos(-ROT_SPEED);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(-ROT_SPEED)
		- cub->player.plane_y * sin(-ROT_SPEED);
	cub->player.plane_y = old_plane_x * sin(-ROT_SPEED)
		+ cub->player.plane_y * cos(-ROT_SPEED);
}

// Rotates the player's view to the right.
void	cb_rotate_right(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(ROT_SPEED)
		- cub->player.dir_y * sin(ROT_SPEED);
	cub->player.dir_y = old_dir_x * sin(ROT_SPEED)
		+ cub->player.dir_y * cos(ROT_SPEED);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(ROT_SPEED)
		- cub->player.plane_y * sin(ROT_SPEED);
	cub->player.plane_y = old_plane_x * sin(ROT_SPEED)
		+ cub->player.plane_y * cos(ROT_SPEED);
}

// Initializes the player's direction and camera for North or South.
static void	cb_init_player_pos_x(t_cub3d *cub, char c)
{
	if (c == 'N')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = -1;
		cub->player.plane_x = 0.66;
		cub->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = 1;
		cub->player.plane_x = -0.66;
		cub->player.plane_y = 0;
	}
}

// Initializes the player's direction and camera for East or West.
static void	cb_init_player_pos_y(t_cub3d *cub, char c)
{
	if (c == 'E')
	{
		cub->player.dir_x = 1;
		cub->player.dir_y = 0;
		cub->player.plane_x = 0;
		cub->player.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.dir_y = 0;
		cub->player.plane_x = 0;
		cub->player.plane_y = -0.66;
	}
}

// Sets the player's initial position based on the map character.
void	cb_init_player_pos(t_cub3d *cub, char c, int x, int y)
{
	cub->player.pos_x = x + 0.5;
	cub->player.pos_y = y + 0.5;
	if (c == 'N' || c == 'S')
		cb_init_player_pos_x(cub, c);
	else if (c == 'E' || c == 'W')
		cb_init_player_pos_y(cub, c);
	cub->map.grid[y][x] = '0';
}
