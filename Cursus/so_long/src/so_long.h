/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/30 17:13:48 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "MLX42.h"

typedef struct s_mlx {
}	t_mlx;

typedef struct s_mlx_texture {
}	t_mlx_texture;

typedef struct s_mlx_image {
}	t_mlx_image;

typedef struct s_game {
	t_mlx			*mlx;
	t_mlx_texture	*player_texture;
	t_mlx_texture	*wall_texture;
	t_mlx_texture	*collectible_texture;
	t_mlx_texture	*exit_texture;
	t_mlx_image		*player_image;
	t_mlx_image		*wall_image;
	t_mlx_image		*collectible_image;
	t_mlx_image		*exit_image;
	char			**map;
	int				map_width;
	int				map_height;
}	t_game;

char		**read_map(const char *filename, int *width, int *height);
char		*get_next_map_line(int fd);
int			determine_map_dimensions(int fd, int *width, int *height);
char		**allocate_map_memory(int width, int height);
void		allocate_rows(char **map, int width, int height, int current_row);
void		populate_map(int fd, char **map, int height);
void		free_map_memory(char **map, int height);
char		*ft_strcpy(char *dest, const char *src);
void		load_textures(t_game *game);
void		create_images(t_game *game);
int			initialize_mlx(t_game *game, int map_width,
				int map_height, int TILE_SIZE);

#endif
