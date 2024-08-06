/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:52:01 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/06 12:03:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_up(t_game *game, t_point p, int step)
{
	if (step % 2 == 0 && game->image.p_u_1 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_u_1,
			p.x * 64, p.y * 64);
	else if (game->image.p_u_2 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_u_2,
			p.x * 64, p.y * 64);
}

void	draw_player_down(t_game *game, t_point p, int step)
{
	if (step % 2 == 0 && game->image.p_d_1 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_d_1,
			p.x * 64, p.y * 64);
	else if (game->image.p_d_2 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_d_2,
			p.x * 64, p.y * 64);
}

void	draw_player_left(t_game *game, t_point p, int step)
{
	if (step % 2 == 0 && game->image.p_l_1 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_l_1,
			p.x * 64, p.y * 64);
	else if (game->image.p_l_2 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_l_2,
			p.x * 64, p.y * 64);
}

void	draw_player_right(t_game *game, t_point p, int step)
{
	if (step % 2 == 0 && game->image.p_r_1 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_r_1,
			p.x * 64, p.y * 64);
	else if (game->image.p_r_2 != NULL)
		mlx_image_to_window(game->mlx, game->image.p_r_2,
			p.x * 64, p.y * 64);
}
