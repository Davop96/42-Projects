/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/06 12:05:37 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->texture.wall = mlx_load_png("./assets/misc/wall.png");
	if (!game->texture.wall)
	{
		mlx_terminate(game->mlx);
		free_game(game, 1);
		exit (1);
	}
	game->texture.ground = mlx_load_png("./assets/misc/ground.png");
	game->texture.player = mlx_load_png("./assets/char/b-1.png");
	game->texture.p_d_1 = mlx_load_png("./assets/char/b-2.png");
	game->texture.p_d_2 = mlx_load_png("./assets/char/b-3.png");
	game->texture.p_u_1 = mlx_load_png("./assets/char/b-5.png");
	game->texture.p_u_2 = mlx_load_png("./assets/char/b-6.png");
	game->texture.p_r_1 = mlx_load_png("./assets/char/b-8.png");
	game->texture.p_r_2 = mlx_load_png("./assets/char/b-9.png");
	game->texture.p_l_1 = mlx_load_png("./assets/char/b-11.png");
	game->texture.p_l_2 = mlx_load_png("./assets/char/b-12.png");
	game->texture.collec = mlx_load_png("./assets/collec/ball-1.png");
	game->texture.exit = mlx_load_png("./assets/misc/exit.png");
}

void	create_images_from_textures(t_game *game)
{
	game->image.wall = mlx_texture_to_image(game->mlx, game->texture.wall);
	game->image.ground = mlx_texture_to_image(game->mlx, game->texture.ground);
	game->image.player = mlx_texture_to_image(game->mlx, game->texture.player);
	game->image.p_d_1 = mlx_texture_to_image(game->mlx, game->texture.p_d_1);
	game->image.p_d_2 = mlx_texture_to_image(game->mlx, game->texture.p_d_2);
	game->image.p_u_1 = mlx_texture_to_image(game->mlx, game->texture.p_u_1);
	game->image.p_u_2 = mlx_texture_to_image(game->mlx, game->texture.p_u_2);
	game->image.p_r_1 = mlx_texture_to_image(game->mlx, game->texture.p_r_1);
	game->image.p_r_2 = mlx_texture_to_image(game->mlx, game->texture.p_r_2);
	game->image.p_l_1 = mlx_texture_to_image(game->mlx, game->texture.p_l_1);
	game->image.p_l_2 = mlx_texture_to_image(game->mlx, game->texture.p_l_2);
	game->image.collec = mlx_texture_to_image(game->mlx, game->texture.collec);
	game->image.exit = mlx_texture_to_image(game->mlx, game->texture.exit);
}

void	hook_images(t_game *game, char letter, t_point p)
{
	if (letter == '1' && game->image.wall != NULL)
		mlx_image_to_window(game->mlx, game->image.wall, p.x * 64, p.y * 64);
	if (letter != '1' && game->image.ground != NULL)
		mlx_image_to_window(game->mlx, game->image.ground, p.x * 64, p.y * 64);
	if (letter == 'P')
	{
		hook_images_player(game, p);
		return ;
	}
	if (letter == 'C' && game->image.collec != NULL)
		mlx_image_to_window(game->mlx, game->image.collec, p.x * 64, p.y * 64);
	if (letter == 'E' && game->image.exit != NULL)
		mlx_image_to_window(game->mlx, game->image.exit, p.x * 64, p.y * 64);
}

void	hook_images_player(t_game *game, t_point p)
{
	mlx_image_to_window(game->mlx, game->image.player, p.x * 64, p.y * 64);
	if (game->direction == 'U')
		draw_player_up(game, p, game->counter);
	else if (game->direction == 'D')
		draw_player_down(game, p, game->counter);
	else if (game->direction == 'L')
		draw_player_left(game, p, game->counter);
	else if (game->direction == 'R')
		draw_player_right(game, p, game->counter);
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
	hook_images_player(game, game->player);
}
