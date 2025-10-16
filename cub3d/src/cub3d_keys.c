/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:42:28 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:36:54 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handles keyboard input events for player movement and rotation.
void	cb_key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub;

	cub = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			cb_mlx_cleanup(cub);
		else if (keydata.key == MLX_KEY_W)
			cb_move_forward(cub);
		else if (keydata.key == MLX_KEY_S)
			cb_move_backward(cub);
		else if (keydata.key == MLX_KEY_A)
			cb_move_left(cub);
		else if (keydata.key == MLX_KEY_D)
			cb_move_right(cub);
		else if (keydata.key == MLX_KEY_LEFT)
			cb_rotate_left(cub);
		else if (keydata.key == MLX_KEY_RIGHT)
			cb_rotate_right(cub);
	}
}
