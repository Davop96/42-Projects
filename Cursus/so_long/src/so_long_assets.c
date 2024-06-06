/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 16:55:41 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->textures.player = mlx_load_png("assets/characters/brendan-1.png");
	game->textures.wall = mlx_load_png("assets/misc/wall.png");
	game->textures.ground = mlx_load_png("assets/misc/ground.png");
	game->textures.collectible = mlx_load_png("assets/collec/ball-1.png");
	game->textures.exit = mlx_load_png("assets/misc/exit.png");
}

void	delete_textures(t_game *game)
{
	if (game->textures.player)
		mlx_delete_texture(game->textures.player);
	if (game->textures.wall)
		mlx_delete_texture(game->textures.wall);
	if (game->textures.ground)
		mlx_delete_texture(game->textures.ground);
	if (game->textures.collectible)
		mlx_delete_texture(game->textures.collectible);
	if (game->textures.exit)
		mlx_delete_texture(game->textures.exit);
}

void	create_images_from_textures(t_game *game)
{
	game->images.player = mlx_texture_to_image
		(game->mlx, game->textures.player);
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->images.ground = mlx_texture_to_image
		(game->mlx, game->textures.ground);
	game->images.collectible = mlx_texture_to_image
		(game->mlx, game->textures.collectible);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
}

void	delete_images(t_game *game)
{
	if (game->images.player)
		mlx_delete_image(game->mlx, game->images.player);
	if (game->images.wall)
		mlx_delete_image(game->mlx, game->images.wall);
	if (game->images.ground)
		mlx_delete_image(game->mlx, game->images.ground);
	if (game->images.collectible)
		mlx_delete_image(game->mlx, game->images.collectible);
	if (game->images.exit)
		mlx_delete_image(game->mlx, game->images.exit);
}

void	verify_images(t_game *game)
{
	if (!game->textures.player || !game->textures.wall || !game->textures.ground
		|| !game->textures.collectible || !game->textures.exit)
	{
		ft_printf("Error: Failed to load one or more textures\n");
		delete_textures(game);
		exit(EXIT_FAILURE);
	}
	create_images_from_textures(game);
	if (!game->images.player || !game->images.wall || !game->images.ground
		|| !game->images.collectible || !game->images.exit)
	{
		ft_printf("Error: Failed to create one or more images\n");
		delete_images(game);
		exit(EXIT_FAILURE);
	}
}
