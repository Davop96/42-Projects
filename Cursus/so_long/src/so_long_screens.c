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

#define DISCLAIMER_IMAGE_PATH "assets/misc/disclaimer.png"

void	disclaimer_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->mlx, game->images.disclaimer);
		start_game(game);
	}
}

void	show_disclaimer(t_game *game)
{
	game->textures.disclaimer = mlx_load_png(DISCLAIMER_IMAGE_PATH);
	if (!game->textures.disclaimer)
	{
		ft_printf("Error: Failed to load disclaimer image\n");
		exit(EXIT_FAILURE);
	}
	game->images.disclaimer
		= mlx_texture_to_image(game->mlx, game->textures.disclaimer);
	if (!game->images.disclaimer)
	{
		ft_printf("Error: Failed to convert disclaimer texture to image\n");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(game->mlx, game->images.disclaimer, 0, 0);
	mlx_key_hook(game->mlx, disclaimer_key_hook, game);
	mlx_delete_texture(game->textures.disclaimer);
}
