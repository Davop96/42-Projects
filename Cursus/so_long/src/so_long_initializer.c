/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/04 14:58:51 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init(1600, 1200, "GTA VI", false);
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (1);
	}
	return (0);
}

void	initialize_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, (mlx_keyfunc)handle_input, game);
	mlx_close_hook(game->mlx, (mlx_closefunc)close_window, game);
}

void	initialize_game(t_game *game)
{
	game->collectibles = 0;
	game->moves = 0;
}
