/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/04 14:44:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

#define TILE_SIZE 32

void	find_player_and_collectibles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	load_textures(game);
	create_images(game);
	initialize_hooks(game);
	mlx_loop(game->mlx);
	free_map_memory(game->map, game->map_height);
}


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	initialize_game(&game);
	game.map = read_map(argv[1], &game.map_width, &game.map_height);
	if (!game.map)
	{
		ft_printf("Error: Failed to read map\n");
		return (1);
	}
	find_player_and_collectibles(&game);
	if (initialize_mlx(&game))
	{
		free_map_memory(game.map, game.map_height);
		return (1);
	}
	start_game(&game);
	return (0);
}







