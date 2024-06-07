/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/07 15:29:47 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	if (game->images.disclaimer)
	{
		window_width = game->images.disclaimer->width;
		window_height = game->images.disclaimer->height;
	}
	else
	{
		window_width = game->map_width * TILE_SIZE;
		window_height = game->map_height * TILE_SIZE;
	}
	game->mlx = mlx_init(window_width, window_height, "GTA VI", false);
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (1);
	}
	return (0);
}

void	initialize_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, (mlx_closefunc)close_window, game);
}

void	initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->textures.player = NULL;
	game->textures.wall = NULL;
	game->textures.ground = NULL;
	game->textures.collectible = NULL;
	game->textures.exit = NULL;
	game->textures.disclaimer = NULL;
	game->images.player = NULL;
	game->images.wall = NULL;
	game->images.ground = NULL;
	game->images.collectible = NULL;
	game->images.exit = NULL;
	game->images.disclaimer = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->moves = 0;
}
