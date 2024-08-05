/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/05 22:01:45 by dbohoyo-         ###   ########.fr       */
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
	game->texture.player = mlx_load_png("./assets/char/b-0.png");
	game->texture.p_d = mlx_load_png("./assets/char/b-1.png");
	game->texture.p_d_w1 = mlx_load_png("./assets/char/b-2.png");
	game->texture.p_d_w2 = mlx_load_png("./assets/char/b-3.png");
	game->texture.p_u = mlx_load_png("./assets/char/b-4.png");
	game->texture.p_u_w1 = mlx_load_png("./assets/char/b-5.png");
	game->texture.p_u_w2 = mlx_load_png("./assets/char/b-6.png");
	game->texture.p_r = mlx_load_png("./assets/char/b-7.png");
	game->texture.p_r_w1 = mlx_load_png("./assets/char/b-8.png");
	game->texture.p_r_w2 = mlx_load_png("./assets/char/b-9.png");
	game->texture.p_l = mlx_load_png("./assets/char/b-10.png");
	game->texture.p_l_w1 = mlx_load_png("./assets/char/b-11.png");
	game->texture.p_l_w2 = mlx_load_png("./assets/char/b-12.png");
	game->texture.collec = mlx_load_png("./assets/collec/ball-1.png");
	game->texture.exit = mlx_load_png("./assets/misc/exit.png");
	//game->texture.enemy = mlx_load_png("./assets/misc/enemy.png");
}

void	create_images_from_textures(t_game *game)
{
	game->image.wall = mlx_texture_to_image(game->mlx, game->texture.wall);
	game->image.ground = mlx_texture_to_image(game->mlx, game->texture.ground);
	game->image.player = mlx_texture_to_image(game->mlx, game->texture.player);
	game->image.p_d = mlx_texture_to_image(game->mlx, game->texture.p_d);
	game->image.p_d_w1 = mlx_texture_to_image(game->mlx, game->texture.p_d_w1);
	game->image.p_d_w2 = mlx_texture_to_image(game->mlx, game->texture.p_d_w2);
	game->image.p_u = mlx_texture_to_image(game->mlx, game->texture.p_u);
	game->image.p_u_w1 = mlx_texture_to_image(game->mlx, game->texture.p_u_w1);
	game->image.p_u_w2 = mlx_texture_to_image(game->mlx, game->texture.p_u_w2);
	game->image.p_r = mlx_texture_to_image(game->mlx, game->texture.p_r);
	game->image.p_r_w1 = mlx_texture_to_image(game->mlx, game->texture.p_r_w1);
	game->image.p_r_w2 = mlx_texture_to_image(game->mlx, game->texture.p_r_w2);
	game->image.p_l = mlx_texture_to_image(game->mlx, game->texture.p_l);
	game->image.p_l_w1 = mlx_texture_to_image(game->mlx, game->texture.p_l_w1);
	game->image.p_l_w2 = mlx_texture_to_image(game->mlx, game->texture.p_l_w2);
	game->image.collec = mlx_texture_to_image(game->mlx, game->texture.collec);
	game->image.exit = mlx_texture_to_image(game->mlx, game->texture.exit);
	//game->image.enemy = mlx_texture_to_image(game->mlx, game->texture.enemy);
}

void	hook_images(t_game *game, char letter, t_point p)
{
	if (letter == '1' && game->image.wall != NULL)
		mlx_image_to_window(game->mlx, game->image.wall, p.x * 32, p.y * 32);
	if (letter != '1' && game->image.ground != NULL)
		mlx_image_to_window(game->mlx, game->image.ground, p.x * 32, p.y * 32);
	if (letter == 'P')
	{
		hook_images_player(game, p);
		return ;
	}
	if (letter == 'C' && game->image.collec != NULL)
		mlx_image_to_window(game->mlx, game->image.collec, p.x * 32, p.y * 32);
	if (letter == 'E' && game->image.exit != NULL)
		mlx_image_to_window(game->mlx, game->image.exit, p.x * 32, p.y * 32);
}

void	hook_images_player(t_game *game, t_point p)
{
	mlx_image_to_window(game->mlx, game->image.player, p.x * 32, p.y * 32);
	if (game->direction == 'U')
		draw_player_up(game, p, game->t_walk, game->counter);
	else if (game->direction == 'D')
		draw_player_down(game, p, game->t_walk, game->counter);
	else if (game->direction == 'L')
		draw_player_left(game, p, game->t_walk, game->counter);
	else if (game->direction == 'R')
		draw_player_right(game, p, game->t_walk, game->counter);
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
