/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_screens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:16 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 10:39:16 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_disclaimer(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE || keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

void	show_disclaimer(mlx_t *mlx)
{
	mlx_image_t	*disclaimer_image;

	disclaimer_image = mlx_new_image(mlx, 1600, 1200);
	if (!disclaimer_image)
	{
		ft_printf("Error: Failed to create disclaimer image\n");
		exit(1);
	}
	mlx_put_string(mlx,
		"All assets used in this game belong to Nintendo and Gamefreak.",
		400, 300);
	mlx_put_string(mlx, "Press any key to continue...", 400, 350);
	mlx_key_hook(mlx, key_hook_disclaimer, mlx);
	mlx_image_to_window(mlx, disclaimer_image, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, disclaimer_image);
}
