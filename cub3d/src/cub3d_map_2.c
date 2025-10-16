/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:20:05 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/09 12:59:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Auxiliar function for cb_process_map_lines that processes a single line.
int	cb_process_single_map_line(char *line, t_map *map,
			t_texture *textures, t_map_line_ctx *ctx)
{
	cb_parse_texture_line(line, textures);
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		if (cb_parse_color_line(line, ctx->cub) == 0)
		{
			if (line[0] == 'F')
				*(ctx->color_f_found) = 1;
			if (line[0] == 'C')
				*(ctx->color_c_found) = 1;
		}
		else
		{
			close(ctx->fd);
			return (1);
		}
	}
	cb_add_map_row(line, map, ctx);
	return (0);
}

// Processes each line of the map file and extracts relevant data.
int	cb_process_map_lines(int fd, t_map *map, t_texture *textures,
			t_map_line_ctx *ctx)
{
	char	*line;

	*(ctx->row) = 0;
	*(ctx->max_width) = 0;
	*(ctx->player_count) = 0;
	ctx->fd = fd;
	line = get_next_line(fd);
	while (line)
	{
		if (cb_process_single_map_line(line, map, textures, ctx) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	map->height = *(ctx->row);
	map->width = *(ctx->max_width);
	cb_pad_map_rows(map, *(ctx->max_width));
	return (0);
}

// Auxiliar for cb_parse_texture_line that extracts the texture path from a line
void	cb_extract_texture_path(char *line, char **texture_path, int prefix_len)
{
	int	len;

	while (line[prefix_len] == ' ')
		prefix_len++;
	len = ft_strlen(line + prefix_len);
	if (len > 0 && (line[prefix_len + len - 1] == '\n'
			|| line[prefix_len + len - 1] == '\r'))
		len--;
	*texture_path = ft_strndup(line + prefix_len, len);
}

// Call to extract the texture path of a line based on the prefix.
void	cb_parse_texture_line(char *line, t_texture *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cb_extract_texture_path(line, &textures->north_path, 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cb_extract_texture_path(line, &textures->south_path, 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cb_extract_texture_path(line, &textures->west_path, 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cb_extract_texture_path(line, &textures->east_path, 3);
}
