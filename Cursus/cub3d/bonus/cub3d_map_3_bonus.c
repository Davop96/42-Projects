/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:46:56 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/25 14:47:15 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Initializes part of the auxiliary structure
void	cb_init_map_line_ctx_a(t_map_line_ctx *ctx, int fd, t_cub3d *cub)
{
	static int	row;
	static int	max_width;
	static int	player_count;

	row = 0;
	max_width = 0;
	player_count = 0;
	ctx->row = &row;
	ctx->max_width = &max_width;
	ctx->player_count = &player_count;
	ctx->fd = fd;
	ctx->cub = cub;
}

// Initializes part of the auxiliary structure
void	cb_init_map_line_ctx_b(t_map_line_ctx *ctx, int *color_f_found,
		int *color_c_found)
{
	ctx->color_f_found = color_f_found;
	ctx->color_c_found = color_c_found;
}

// Main logic for loading, processing and validating the map.
int	cb_load_map(const char *filename, t_map *map, t_texture *textures,
	t_cub3d *cub)
{
	int				fd;
	int				color_f_found;
	int				color_c_found;
	t_map_line_ctx	ctx;

	printf("Opening map file: %s\n", filename);
	fd = cb_open_map_file(filename);
	if (fd < 0)
		return (1);
	if (!cb_prepare_map_grid(map))
	{
		close(fd);
		return (1);
	}
	color_f_found = 0;
	color_c_found = 0;
	cb_init_map_line_ctx_a(&ctx, fd, cub);
	cb_init_map_line_ctx_b(&ctx, &color_f_found, &color_c_found);
	cb_process_map_lines(fd, map, textures, &ctx);
	close(fd);
	if (cb_validate_map_data(textures, color_f_found, color_c_found))
		return (1);
	return (0);
}
