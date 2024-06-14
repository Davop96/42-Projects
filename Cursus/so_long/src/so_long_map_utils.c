/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:59:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 01:10:00 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_x(t_map *lst)
{
	int	x;

	x = 0;
	while (lst->map[x] != '\n')
		x++;
	return (x);
}

int	map_size_y(t_map *lst)
{
	int	y;

	y = 0;
	while (lst)
	{
		y++;
		lst = lst->next;
	}
	return (y);
}

char	**make_matrix(t_game *game)
{
	char	**matrix;
	t_map	*temp;
	int		i;

	i = 0;
	temp = game->map;
	matrix = malloc(sizeof(char *) * (game->size.y + 1));
	if (!matrix)
		return (NULL);
	while (game->map)
	{
		matrix[i] = ft_strdup(game->map->map);
		i++;
		game->map = game->map->next;
	}
	game->map = temp;
	return (matrix);
}
