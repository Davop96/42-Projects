/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 14:44:31 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->player_texture = mlx_load_png("assets/characters/brendan-1.png");
	game->wall_texture = mlx_load_png("assets/misc/wall.png");
	game->ground_texture = mlx_load_png("assets/misc/ground.png");
	game->collectible_texture = mlx_load_png("assets/collec/ball-1.png");
	game->exit_texture = mlx_load_png("assets/misc/exit.png");
}

void	verify_images(t_game *game)
{
	if (!game->player_image || !game->wall_image
		|| !game->ground_image || !game->collectible_image || !game->exit_image)
	{
		ft_printf("Error: Failed to create images\n");
		if (game->player_image)
			mlx_delete_image(game->mlx, game->player_image);
		if (game->wall_image)
			mlx_delete_image(game->mlx, game->wall_image);
		if (game->ground_image)
			mlx_delete_image(game->mlx, game->ground_image);
		if (game->collectible_image)
			mlx_delete_image(game->mlx, game->collectible_image);
		if (game->exit_image)
			mlx_delete_image(game->mlx, game->exit_image);
		mlx_delete_texture(game->player_texture);
		mlx_delete_texture(game->wall_texture);
		mlx_delete_texture(game->ground_texture);
		mlx_delete_texture(game->collectible_texture);
		mlx_delete_texture(game->exit_texture);
		exit(EXIT_FAILURE);
	}
}

void	create_images(t_game *game)
{
	load_textures(game);
	verify_images(game);
}
