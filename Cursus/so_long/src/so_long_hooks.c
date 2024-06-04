/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:54:12 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/04 15:59:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	close_window(t_game *game)
{
	ft_printf("Game Over\n");
	mlx_terminate(game->mlx);
	free_map_memory(game->map, game->map_height);
	exit(0);
}


void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0) 
	{
		ft_printf("¡Winner!\n");
		close_window(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		key;

	game = (t_game *)param;
	key = keydata.key;

	if (key == MLX_KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	if (key == MLX_KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	if (key == MLX_KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	if (key == MLX_KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	if (key == MLX_KEY_ESCAPE)
		close_window(game);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	handle_input(keydata, param);
}



