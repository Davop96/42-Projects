/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/30 13:04:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

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

#endif
