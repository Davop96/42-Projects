/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 02:57:54 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *game)
{
	game = find_player(game);
	game->mlx = mlx_init(game->size.x * 32, game->size.y * 32, "so_long", true);
	load_textures(game);
	create_images_from_textures(game);
	build_map(game);
	mlx_key_hook(game->mlx, hook_keys, game);
	mlx_loop(game->mlx);
}

void	initialize_obj(t_object *objects)
{
	t_object	temp;

	temp = *objects;
	temp.collec = 0;
	temp.player = 0;
	temp.exit = 0;
	temp.enemy = 0;
	*objects = temp;
}

t_game	*init_game(t_game *game)
{
	game->path = NULL;
	game->map = NULL;
	game->matrix = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->size.y = 0;
	game->size.x = 0;
	game->moves = 0;
	game->c = 0;
	game->balls = 0;
	game->flag = 0;
	game->mlx = NULL;
	return (game);
}

int	start_map(t_game **game)
{
	t_game	*temp;

	temp = *game;
	temp->map = make_map(temp);
	if (!temp->map)
	{
		free(temp);
		return (1);
	}
	temp->size.y = map_size_y(temp->map);
	temp->size.x = map_size_x(temp->map);
	temp->matrix = make_matrix(temp);
	if (!temp->matrix)
	{
		free_game(temp, 2);
		return (1);
	}
	temp->matrix2 = make_matrix(temp);
	if (!temp->matrix2)
	{
		free_game(temp, 1);
		return (1);
	}
	*game = temp;
	return (0);
}

int	initializes_map(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game = init_game(game);
	game->path = path;
	if (start_map(&game) == 1)
		return (1);
	game = find_player(game);
	game = flood_fill(game);
	game->matrix2 = free_matrix(game->matrix2, game->size.y);
	if (check_errors(game, map_objects(game->map)) == 1)
	{
		free_game(game, 1);
		return (1);
	}
	start_mlx(game);
	free_game(game, 0);
	return (0);
}
