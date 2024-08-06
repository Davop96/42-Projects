/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:24 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/06 12:45:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	**check_tab(t_game	**game, char to_check)
{
	if (to_check == 'C')
	{
		(*game)->object.collec++;
		(*game)->balls++;
	}
	if (to_check == 'P')
		(*game)->object.player++;
	if (to_check == 'E')
		(*game)->object.exit++;
	return (game);
}

t_game	**fill(char **tab, t_point size, t_point cur, t_game **game)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return (game);
	if (tab[cur.y][cur.x] == 'E')
	{
		tab[cur.y][cur.x] = 'F';
		(*game)->object.exit++;
		return (game);
	}
	game = check_tab(game, tab[cur.y][cur.x]);
	tab[cur.y][cur.x] = 'F';
	game = fill(tab, size, (t_point){cur.x - 1, cur.y}, game);
	game = fill(tab, size, (t_point){cur.x + 1, cur.y}, game);
	game = fill(tab, size, (t_point){cur.x, cur.y - 1}, game);
	game = fill(tab, size, (t_point){cur.x, cur.y + 1}, game);
	return (game);
}

t_game	*flood_fill(t_game *game)
{
	game->object.collec = 0;
	game->object.exit = 0;
	game->object.player = 0;
	game = *fill(game->matrix2, game->size, game->player, &game);
	return (game);
}

int	key_check(t_game *game)
{
	if (game->matrix[game->player.y - 1][game->player.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (1);
	if (game->matrix[game->player.y + 1][game->player.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (2);
	if (game->matrix[game->player.y][game->player.x - 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (3);
	if (game->matrix[game->player.y][game->player.x + 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (4);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (5);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	total_size;
	size_t	x;

	total_size = count * size;
	pt = malloc(total_size);
	if (pt == NULL)
		return (NULL);
	x = 0;
	while (x < total_size)
	{
		((char *)pt)[x] = 0;
		x++;
	}
	return (pt);
}
