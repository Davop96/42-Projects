/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_moves_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:53:41 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:49:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Moves the player forward if there is no wall.
void	cb_move_forward(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.dir_x * MOVE_SPEED;
	new_y = cub->player.pos_y + cub->player.dir_y * MOVE_SPEED;
	if (new_y >= 0 && new_y < cub->map.height
		&& cub->player.pos_x >= 0 && cub->player.pos_x < cub->map.width
		&& cub->map.grid[(int)new_y][(int)cub->player.pos_x] == '0')
		cub->player.pos_y = new_y;
	if (cub->player.pos_y >= 0 && cub->player.pos_y < cub->map.height
		&& new_x >= 0 && new_x < cub->map.width
		&& cub->map.grid[(int)cub->player.pos_y][(int)new_x] == '0')
		cub->player.pos_x = new_x;
}

// Moves the player backward if there is no wall.
void	cb_move_backward(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.dir_x * MOVE_SPEED;
	new_y = cub->player.pos_y - cub->player.dir_y * MOVE_SPEED;
	if (new_y >= 0 && new_y < cub->map.height
		&& cub->player.pos_x >= 0 && cub->player.pos_x < cub->map.width
		&& cub->map.grid[(int)new_y][(int)cub->player.pos_x] == '0')
		cub->player.pos_y = new_y;
	if (cub->player.pos_y >= 0 && cub->player.pos_y < cub->map.height
		&& new_x >= 0 && new_x < cub->map.width
		&& cub->map.grid[(int)cub->player.pos_y][(int)new_x] == '0')
		cub->player.pos_x = new_x;
}

// Moves the player to the left if there is no wall.
void	cb_move_left(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.plane_x * MOVE_SPEED;
	new_y = cub->player.pos_y - cub->player.plane_y * MOVE_SPEED;
	if (new_y >= 0 && new_y < cub->map.height
		&& cub->player.pos_x >= 0 && cub->player.pos_x < cub->map.width
		&& cub->map.grid[(int)new_y][(int)cub->player.pos_x] == '0')
		cub->player.pos_y = new_y;
	if (cub->player.pos_y >= 0 && cub->player.pos_y < cub->map.height
		&& new_x >= 0 && new_x < cub->map.width
		&& cub->map.grid[(int)cub->player.pos_y][(int)new_x] == '0')
		cub->player.pos_x = new_x;
}

// Moves the player to the right if there is no wall.
void	cb_move_right(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.plane_x * MOVE_SPEED;
	new_y = cub->player.pos_y + cub->player.plane_y * MOVE_SPEED;
	if (new_y >= 0 && new_y < cub->map.height
		&& cub->player.pos_x >= 0 && cub->player.pos_x < cub->map.width
		&& cub->map.grid[(int)new_y][(int)cub->player.pos_x] == '0')
		cub->player.pos_y = new_y;
	if (cub->player.pos_y >= 0 && cub->player.pos_y < cub->map.height
		&& new_x >= 0 && new_x < cub->map.width
		&& cub->map.grid[(int)cub->player.pos_y][(int)new_x] == '0')
		cub->player.pos_x = new_x;
}

// Finds the player's position and initializes their direction.
void	cb_init_player(t_cub3d *cub)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			c = cub->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				cb_init_player_pos(cub, c, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
	printf("Error: no player position found in map\n");
	exit(1);
}
