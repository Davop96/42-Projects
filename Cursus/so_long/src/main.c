/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:03 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_and_collectibles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->collectibles = 0;
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

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall_image, j
					* TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->collectible_image, j
					* TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit_image, j
					* TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->player_image, j
					* TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	show_disclaimer(game->mlx);
	load_textures(game);
	create_images(game);
	render_map(game);
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
