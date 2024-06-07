/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:57:17 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/07 15:23:06 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	render_ground(game);
	render_elements(game);
}

void render_elements(t_game *game)
{
    int i;
    int j;

    // Renderiza el suelo en todas las casillas
    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            mlx_image_to_window(game->mlx, game->images.ground, j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }

    // Superpone las otras texturas sobre el suelo
    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == '1') // Renderiza la textura de la pared
                mlx_image_to_window(game->mlx, game->images.wall, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'C') // Renderiza la textura del collectible
                mlx_image_to_window(game->mlx, game->images.collectible, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'E') // Renderiza la textura de la salida
                mlx_image_to_window(game->mlx, game->images.exit, j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'P') // Renderiza la textura del jugador
                mlx_image_to_window(game->mlx, game->images.player, j * TILE_SIZE, i * TILE_SIZE);
            // Podrías agregar más condiciones aquí para otras texturas
            j++;
        }
        i++;
    }
}


void	render_ground(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->images.ground,
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
