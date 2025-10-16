/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:23:06 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/07 14:49:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Frees all memory allocated for the map grid.
void	cb_free_map_grid(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

// Frees all allocated textures and MLX resources, then exits the program.
void	cb_mlx_cleanup(t_cub3d *cub)
{
	cb_free_textures(&cub->textures);
	cb_free_map_grid(&cub->map);
	if (cub->game_img && cub->mlx)
		mlx_delete_image(cub->mlx, cub->game_img);
	if (cub->mlx)
		mlx_terminate(cub->mlx);
	exit(0);
}

// Duplicates up to n characters from the source string s.
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
