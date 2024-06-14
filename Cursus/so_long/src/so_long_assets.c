/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 02:03:54 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->texture.wall = mlx_load_png("./assets/misc/wall.png");
	if (!game->texture.wall)
	{
		ft_printf("Error: Wall texture not found.\n");
		mlx_terminate(game->mlx);
		free_game(game, 1);
		exit (1);
	}
	game->texture.ground = mlx_load_png("./assets/misc/ground.png");
	game->texture.player = mlx_load_png("./assets/characters/brendan-1.png");
	game->texture.collec = mlx_load_png("./assets/collec/ball-1.png");
	game->texture.exit = mlx_load_png("./assets/misc/exit.png");
}

void	create_images_from_textures(t_game *game)
{
	game->image.wall = mlx_texture_to_image(game->mlx, game->texture.wall);
	game->image.ground = mlx_texture_to_image(game->mlx, game->texture.ground);
	game->image.player = mlx_texture_to_image(game->mlx, game->texture.player);
	game->image.collec = mlx_texture_to_image(game->mlx, game->texture.collec);
	game->image.exit = mlx_texture_to_image(game->mlx, game->texture.exit);
}

void	hook_images(t_game *game, char letter, t_point p)
{
	if (letter == '1' && game->image.wall != NULL)
		mlx_image_to_window(game->mlx, game->image.wall, p.x * 32, p.y * 32);
	if (letter != '1' && game->image.ground != NULL)
		mlx_image_to_window(game->mlx, game->image.ground, p.x * 32, p.y * 32);
	if (letter == 'P' && game->image.player != NULL)
		mlx_image_to_window(game->mlx, game->image.player, p.x * 32, p.y * 32);
	if (letter == 'C' && game->image.collec != NULL)
		mlx_image_to_window(game->mlx, game->image.collec, p.x * 32, p.y * 32);
	if (letter == 'E' && game->image.exit != NULL)
		mlx_image_to_window(game->mlx, game->image.exit, p.x * 32, p.y * 32);
}

void	build_map(t_game *game)
{
	t_point	pos;
	int		j;
	int		i;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			pos.x = i;
			pos.y = j;
			hook_images(game, game->matrix[j][i], pos);
			i++;
		}
		j++;
	}
}
