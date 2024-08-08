/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/08 16:32:21 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*p_d_1;
	mlx_texture_t	*p_d_2;
	mlx_texture_t	*p_u_1;
	mlx_texture_t	*p_u_2;
	mlx_texture_t	*p_l_1;
	mlx_texture_t	*p_l_2;
	mlx_texture_t	*p_r_1;
	mlx_texture_t	*p_r_2;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
}	t_texture;

typedef struct s_image
{
	mlx_image_t		*player;
	mlx_image_t		*p_d_1;
	mlx_image_t		*p_d_2;
	mlx_image_t		*p_u_1;
	mlx_image_t		*p_u_2;
	mlx_image_t		*p_l_1;
	mlx_image_t		*p_l_2;
	mlx_image_t		*p_r_1;
	mlx_image_t		*p_r_2;
	mlx_image_t		*wall;
	mlx_image_t		*ground;
	mlx_image_t		*collec;
	mlx_image_t		*exit;
}	t_image;

typedef struct s_object
{
	int	player;
	int	wall;
	int	collec;
	int	exit;
}	t_object;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

typedef struct s_key_data
{
	int	key;
}	t_key_data;

typedef struct s_game
{
	mlx_t			*mlx;
	t_texture		texture;
	t_image			image;
	t_object		object;
	t_map			*map;
	t_point			player;
	t_point			size;
	char			**matrix;
	char			**matrix2;
	char			*path;
	int				moves;
	int				c;
	int				balls;
	int				flag;
	char			direction;
	bool			t_walk;
	int				counter;
}	t_game;

// Map Utilities
t_game		**check_tab(t_game	**game, char to_check);
t_game		**fill(char **tab, t_point size, t_point cur, t_game **game);
t_game		*flood_fill(t_game *game);
int			key_check(t_game *game);
int			map_size_x(t_map *lst);
int			map_size_y(t_map *lst);
char		**make_matrix(t_game *game);
void		process_map_line(t_game *game, char *map_line);
void		*ft_calloc(size_t count, size_t size);
// Map
t_object	map_objects(t_map *map);
void		map_add_back(t_game *game, t_map *new);
t_map		*list_map_line(char *map_line);
t_game		*find_player(t_game *game);
t_map		*make_map(t_game *game);
// Verify
int			check_rectangle(t_game *game);
int			check_borders(t_game *game);
int			check_objects(t_object	checked, t_object objects);
int			check_nbr_objects(t_object objects);
int			check_errors(t_game *game, t_object objects);
int			check_file(char	*path);
// Screens
void		disclaimer_key_hook(mlx_key_data_t keydata, void *param);
void		show_disclaimer(t_game *game);

// Assets
void		load_textures(t_game *game);
void		create_images_from_textures(t_game *game);
void		hook_images(t_game *game, char letter, t_point p);
void		hook_images_player(t_game *game, t_point p);
void		build_map(t_game *game);

// Player
void		draw_player_up(t_game *game, t_point p, int step);
void		draw_player_down(t_game *game, t_point p, int step);
void		draw_player_left(t_game *game, t_point p, int step);
void		draw_player_right(t_game *game, t_point p, int step);
// Movement
void		move_to_up(t_game *game, int y, int x);
void		move_to_down(t_game *game, int y, int x);
void		move_to_left(t_game *game, int y, int x);
void		move_to_right(t_game *game, int y, int x);
void		hook_keys(struct mlx_key_data key_data, void *param);
// Memory
void		stack_clear(t_map **stack);
char		**free_matrix(char	**matrix, int cont);
void		delete_texture(t_game **game);
void		delete_image(t_game **game);
void		free_game(t_game *game, int error);
// Initialization
void		start_mlx(t_game *game);
void		initialize_obj(t_object *objects);
t_game		*init_game(t_game *game);
int			start_map(t_game **game);
int			initializes_map(char *path);

#endif