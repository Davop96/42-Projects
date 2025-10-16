/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:44:29 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/10 13:01:44 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Auxiliary of cb_add_map_row that validates if the row is a valid map row.
int	cb_is_valid_map_line(char *line, int *len)
{
	int	i;
	int	is_map_line;

	is_map_line = 1;
	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
		{
			is_map_line = 0;
			break ;
		}
		i++;
	}
	*len = i;
	return (is_map_line);
}

// Auxiliary of cb_add_map_row that counts the players in the added row.
void	cb_count_players_in_row(t_map *map, t_map_line_ctx *ctx, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (map->grid[*(ctx->row)][i] == 'N' || map->grid[*(ctx->row)][i] == 'S'
		|| map->grid[*(ctx->row)][i] == 'E' || map->grid[*(ctx->row)][i] == 'W')
		{
			(*(ctx->player_count))++;
		}
		i++;
	}
}

// Adds a row to the map starting from a line.
void	cb_add_map_row(char *line, t_map *map, t_map_line_ctx *ctx)
{
	int	len;

	if (!line)
		return ;
	if (cb_is_valid_map_line(line, &len))
	{
		map->grid[*(ctx->row)] = malloc(len + 1);
		if (!map->grid[*(ctx->row)])
		{
			printf("Error: malloc failed for map row %d\n", *(ctx->row));
			exit(1);
		}
		ft_memcpy(map->grid[*(ctx->row)], line, len);
		map->grid[*(ctx->row)][len] = '\0';
		cb_count_players_in_row(map, ctx, len);
		if (len > *(ctx->max_width))
			*(ctx->max_width) = len;
		(*(ctx->row))++;
	}
}
