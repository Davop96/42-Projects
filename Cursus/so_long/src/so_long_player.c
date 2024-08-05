/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:52:01 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/05 20:57:33 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_up(t_game *game, t_point p, bool t_walk, int step)
{
	if (t_walk)
	{
		if (step % 2 == 0 && game->image.p_u_w1 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_u_w1,
				p.x * 32, p.y * 32);
		else if (game->image.p_u_w2 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_u_w2,
				p.x * 32, p.y * 32);
	}
	else if (game->image.p_u != NULL)
		mlx_image_to_window(game->mlx, game->image.p_u, p.x * 32, p.y * 32);
}

void	draw_player_down(t_game *game, t_point p, bool t_walk, int step)
{
	if (t_walk)
	{
		if (step % 2 == 0 && game->image.p_d_w1 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_d_w1,
				p.x * 32, p.y * 32);
		else if (game->image.p_d_w2 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_d_w2,
				p.x * 32, p.y * 32);
	}
	else if (game->image.p_d != NULL)
		mlx_image_to_window(game->mlx, game->image.p_d, p.x * 32, p.y * 32);
}

void	draw_player_left(t_game *game, t_point p, bool t_walk, int step)
{
	if (t_walk)
	{
		if (step % 2 == 0 && game->image.p_l_w1 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_l_w1,
				p.x * 32, p.y * 32);
		else if (game->image.p_l_w2 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_l_w2,
				p.x * 32, p.y * 32);
	}
	else if (game->image.p_l != NULL)
		mlx_image_to_window(game->mlx, game->image.p_l, p.x * 32, p.y * 32);
}

void	draw_player_right(t_game *game, t_point p, bool t_walk, int step)
{
	if (t_walk)
	{
		if (step % 2 == 0 && game->image.p_r_w1 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_r_w1,
				p.x * 32, p.y * 32);
		else if (game->image.p_r_w2 != NULL)
			mlx_image_to_window(game->mlx, game->image.p_r_w2,
				p.x * 32, p.y * 32);
	}
	else if (game->image.p_r != NULL)
		mlx_image_to_window(game->mlx, game->image.p_r, p.x * 32, p.y * 32);
}
