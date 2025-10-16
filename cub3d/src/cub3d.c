/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:49:19 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 14:50:00 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes the MLX42 library and creates the main window.
static void	cb_mlx_init(mlx_t **mlx)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!*mlx)
	{
		printf("Error: MLX42 initialization failed.\n");
		exit(1);
	}
}

// Initializes the cub3d structure, parses arguments and loads the map.
static int	cb_init_cub3d(int argc, char **argv, t_cub3d *cub)
{
	cub->textures.north_path = NULL;
	cub->textures.south_path = NULL;
	cub->textures.east_path = NULL;
	cub->textures.west_path = NULL;
	if (cb_parse_main(argc, argv) == 1)
	{
		cb_mlx_cleanup(cub);
		return (1);
	}
	if (cb_load_map(argv[1], &cub->map, &cub->textures, cub) == 1)
	{
		printf("Error loading map\n");
		cb_mlx_cleanup(cub);
		return (1);
	}
	if (cb_validate_map_all(&cub->map))
	{
		cb_mlx_cleanup(cub);
		return (1);
	}
	cb_init_player(cub);
	return (0);
}

// Loads all textures and weapon frames.
static int	cb_load_resources(t_cub3d *cub)
{
	if (cb_init_textures(&cub->textures) == 1)
	{
		cb_mlx_cleanup(cub);
		return (1);
	}
	return (0);
}

// Sets up MLX, hooks, and starts the main loop.
static void	cb_start_game(t_cub3d *cub)
{
	cb_mlx_init(&cub->mlx);
	mlx_key_hook(cub->mlx, &cb_key_hook, cub);
	mlx_close_hook(cub->mlx, (void *)cb_mlx_cleanup, cub);
	mlx_loop_hook(cub->mlx, (void *)cb_render_game, cub);
	mlx_loop(cub->mlx);
	cb_mlx_cleanup(cub);
	printf("Cub3D execution completed.\n");
}

int	main(int argc, char **argv)
{
	t_cub3d	cub;

	ft_memset(&cub, 0, sizeof(t_cub3d));
	if (cb_init_cub3d(argc, argv, &cub) == 1)
		return (1);
	if (cb_load_resources(&cub) == 1)
		return (1);
	cb_start_game(&cub);
	return (0);
}
