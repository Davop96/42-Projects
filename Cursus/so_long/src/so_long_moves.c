/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:26:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/06 11:39:24 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_up(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y - 1][x] == 'C')
		game->c++;
	else if (game->matrix[y - 1][x] == 'E' && game->c == game->balls)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y - 1][x] == 'E')
		return ;
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y - 1][x] = 'P';
	game->counter++;
	game->direction = 'U';
	game->t_walk = true;
	ft_printf("Moves: %d\n", game->moves);
	hook_images(game, game->matrix[y][x], p);
	p.y--;
	game->t_walk = false;
	hook_images(game, game->matrix[y - 1][x], p);
}

void	move_to_down(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y + 1][x] == 'C')
		game->c++;
	else if (game->matrix[y + 1][x] == 'E' && game->c == game->balls)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y + 1][x] == 'E')
		return ;
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y + 1][x] = 'P';
	game->counter++;
	game->direction = 'D';
	game->t_walk = true;
	ft_printf("Moves: %d\n", game->moves);
	hook_images(game, game->matrix[y][x], p);
	p.y++;
	game->t_walk = false;
	hook_images(game, game->matrix[y + 1][x], p);
}

void	move_to_left(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y][x - 1] == 'C')
		game->c++;
	else if (game->matrix[y][x - 1] == 'E' && game->c == game->balls)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y][x - 1] == 'E')
		return ;
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y][x - 1] = 'P';
	game->counter++;
	game->direction = 'L';
	game->t_walk = true;
	ft_printf("Moves: %d\n", game->moves);
	hook_images(game, game->matrix[y][x], p);
	p.x--;
	game->t_walk = false;
	hook_images(game, game->matrix[y][x - 1], p);
}

void	move_to_right(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y][x + 1] == 'C')
		game->c++;
	else if (game->matrix[y][x + 1] == 'E' && game->c == game->balls)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y][x + 1] == 'E')
		return ;
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y][x + 1] = 'P';
	game->counter++;
	game->direction = 'R';
	game->t_walk = true;
	ft_printf("Moves: %d\n", game->moves);
	hook_images(game, game->matrix[y][x], p);
	p.x++;
	game->t_walk = false;
	hook_images(game, game->matrix[y][x + 1], p);
}

void	hook_keys(struct mlx_key_data key_data, void *param)
{
	t_game	*game;

	game = param;
	game = find_player(game);
	if (key_data.key == MLX_KEY_UP && key_check(game) == 1)
		move_to_up(game, game->player.y, game->player.x);
	if (key_data.key == MLX_KEY_DOWN && key_check(game) == 2)
		move_to_down(game, game->player.y, game->player.x);
	if (key_data.key == MLX_KEY_LEFT && key_check(game) == 3)
		move_to_left(game, game->player.y, game->player.x);
	if (key_data.key == MLX_KEY_RIGHT && key_check(game) == 4)
		move_to_right(game, game->player.y, game->player.x);
	if (key_data.key == MLX_KEY_ESCAPE && key_check(game) == 5)
	{
		mlx_close_window(game->mlx);
		return ;
	}
}
