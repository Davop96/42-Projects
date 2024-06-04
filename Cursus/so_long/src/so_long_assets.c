/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/04 17:07:22 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

#define TILE_SIZE 32

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
		exit(1);
	}
}

//void	render_images(t_game *game)





