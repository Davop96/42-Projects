/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/07 15:54:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define TILE_SIZE 32

typedef struct s_textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*disclaimer;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*ground;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*disclaimer;
}	t_images;

typedef struct s_game
{
	mlx_t			*mlx;
	t_textures		textures;
	t_images		images;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	int				collectibles;
	int				moves;
}	t_game;

// Funciones relacionadas con el mapa
char		**read_map(const char *filename, int *width, int *height);
char		*get_next_map_line(int fd);
int			determine_map_dimensions(int fd, int *width, int *height);
char		**allocate_map_memory(int width, int height);
void		allocate_rows(char **map, int width, int height, int current_row);
void		populate_map(int fd, char **map, int height);
void		free_map_memory(char **map, int height);
// Utilidades
char		*ft_strcpy(char *dest, const char *src);
// Manejo de entradas
void		key_hook(mlx_key_data_t keydata, void *param);
void		handle_input(mlx_key_data_t keydata, void *param);
void		disclaimer_key_hook(mlx_key_data_t keydata, void *param);
// Pantallas
void		show_main_menu(mlx_t *mlx);
void		show_disclaimer(t_game *game);

// Gestión de gráficos y texturas
void		load_textures(t_game *game);
void		delete_textures(t_game *game);
void		create_images_from_textures(t_game *game);
void		delete_images(t_game *game);
void		verify_images(t_game *game);
void		create_images(t_game *game);
void		find_player_and_collectibles(t_game *game);
// Movimientos del jugador
void		move_player(t_game *game, int new_x, int new_y);
// Renderización
void		render_map(t_game *game);
void		render_elements(t_game *game);
void		render_ground(t_game *game);
// Inicialización y cierre del juego
void		close_window(t_game *game);
void		start_game(t_game *game);
int			initialize_mlx(t_game *game);
void		initialize_hooks(t_game *game);
void		initialize_game(t_game *game);

#endif
