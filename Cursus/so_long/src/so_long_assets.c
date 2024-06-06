/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->player_texture = mlx_load_png("assets/characters/brendan-1.png");
	game->wall_texture = mlx_load_png("assets/maps/map.png");
	game->collectible_texture = mlx_load_png("assets/collec/ball-1.png");
	game->exit_texture = mlx_load_png("assets/misc/exit.png");
	if (!game->player_texture || !game->wall_texture
		|| !game->collectible_texture || !game->exit_texture)
	{
		ft_printf("Error: Failed to load textures\n");
		if (game->player_texture)
			mlx_delete_texture(game->player_texture);
		if (game->wall_texture)
			mlx_delete_texture(game->wall_texture);
		if (game->collectible_texture)
			mlx_delete_texture(game->collectible_texture);
		if (game->exit_texture)
			mlx_delete_texture(game->exit_texture);
		exit(1);
	}
}

void	create_images(t_game *game)
{
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx,
			game->collectible_texture);
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	if (!game->player_image || !game->wall_image
		|| !game->collectible_image || !game->exit_image)
	{
		ft_printf("Error: Failed to create images\n");
		if (game->player_image)
			mlx_delete_image(game->mlx, game->player_image);
		if (game->wall_image)
			mlx_delete_image(game->mlx, game->wall_image);
		if (game->collectible_image)
			mlx_delete_image(game->mlx, game->collectible_image);
		if (game->exit_image)
			mlx_delete_image(game->mlx, game->exit_image);
		mlx_delete_texture(game->player_texture);
		mlx_delete_texture(game->wall_texture);
		mlx_delete_texture(game->collectible_texture);
		mlx_delete_texture(game->exit_texture);
		exit(EXIT_FAILURE);
	}
}
