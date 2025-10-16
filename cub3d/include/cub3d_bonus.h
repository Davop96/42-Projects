/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:09:15 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 14:54:57 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h> 
# include <sys/time.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"

# define BOLD_TEXT "\033[1m"
# define RESET_TEXT "\033[0m"

# define MAX_MAP_HEIGHT 100

# define WIDTH 1800
# define HEIGHT 1600

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

# define NUM_WEAPON_FRAMES 4
# define WEAPON_FRAME_DURATION_MS 100

//#define malloc(size) 0

// Texture Structure
typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
}	t_texture;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
}	t_map;

typedef struct s_ray
{
	double			x;
	double			y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	t_map			map;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	double			perp_wall_dist;
}	t_ray;

typedef struct s_stripe_params
{
	mlx_texture_t	*tex;
	int				x;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	double			step;
	double			tex_pos;
}	t_stripe_params;

typedef struct s_weapon
{
	mlx_texture_t	**frames;
	int				num_frames;
	int				current_frame;
	int				animating;
	double			anim_start_time;
}	t_weapon;

typedef struct s_weapon_draw_ctx
{
	mlx_texture_t	*tex;
	int				offset;
	int				screen_x;
	int				screen_y;
	uint32_t		color;
}	t_weapon_draw_ctx;

typedef struct s_cube
{
	mlx_t			*mlx;
	t_texture		textures;
	mlx_image_t		*game_img;
	int32_t			floor_color;
	int32_t			ceiling_color;
	t_ray			player;
	t_map			map;
	t_weapon		weapon;
}	t_cub3d;

typedef struct s_map_line_ctx
{
	int				*row;
	int				*max_width;
	int				*player_count;
	int				*color_f_found;
	int				*color_c_found;
	int				fd;
	t_cub3d			*cub;
}	t_map_line_ctx;

typedef struct s_identifiers_count
{
	int	so;
	int	we;
	int	ea;
	int	no;
	int	c;
	int	f;
}	t_identifiers_count;

// Parse
int			cb_check_number_args(int argc);
int			cb_check_extension(char *argc);
int			cb_parse_main(int argc, char **argv);
int			cb_check_is_map_line(const char *line, int in_map_section);
int			cb_validate_map_single_line(char *line, int *in_map_section);
int			cb_check_map_empty_lines(const char *filename);
void		cb_init_identifiers(t_identifiers_count *c);
void		cb_compare_identifiers(char *line, t_identifiers_count *c);
int			cb_check_identifiers_count(const char *filename);
int			cb_check_map_sect(const char *line);
int			cb_check_line_allowed_chars(const char *line);
int			cb_check_lines_allowed_chars(int fd);
int			cb_check_map_allowed_chars(const char *filename);

// Textures
int			cb_load_texture(mlx_texture_t **texture, char *path);
int			cb_init_textures(t_texture *textures);
void		cb_free_textures(t_texture *textures);
void		cb_render_game(t_cub3d *cub);

// Colours
void		cb_draw_floor_ceiling(t_cub3d *cube);
int			cb_parse_color_line(char *line, t_cub3d *cub);
int			cb_parse_single_value(char *line, int *i);
int			cb_validate_rgb(int r, int g, int b);
int			cb_validate_rgb_count(char *line);
uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y);

//Map
void		cb_init_map_line_ctx_a(t_map_line_ctx *ctx, int fd,
				t_cub3d *cub);
void		cb_init_map_line_ctx_b(t_map_line_ctx *ctx, int *color_f_found,
				int *color_c_found);
int			cb_load_map(const char *filename, t_map *map,
				t_texture *textures, t_cub3d *cub);
char		*cb_create_padded_row(char *row_data, int len, int max_width);
void		cb_pad_map_rows(t_map *map, int max_width);
void		cb_extract_texture_path(char *line,
				char **texture_path, int prefix_len);
void		cb_parse_texture_line(char *line, t_texture *textures);
void		cb_add_map_row(char *line, t_map *map, t_map_line_ctx *ctx);

int			cb_open_map_file(const char *filename);
int			cb_prepare_map_grid(t_map *map);
int			cb_validate_map_data(t_texture *textures, int color_f_found,
				int color_c_found);
int			cb_process_single_map_line(char *line, t_map *map,
				t_texture *textures, t_map_line_ctx *ctx);
int			cb_process_map_lines(int fd, t_map *map, t_texture *textures,
				t_map_line_ctx *ctx);

// Reading
void		cb_draw_wall_stripe(t_cub3d *cub, t_ray *ray, int x);

// Casting
void		cb_cast_ray(t_cub3d *cub, int screen_x, t_ray *ray);
void		cb_calc_ray_dir(t_cub3d *cub, double *ray_dir_x,
				double *ray_dir_y, int screen_x);
void		cb_setup_dda(t_cub3d *cub, double ray_dir_x,
				double ray_dir_y, t_ray *ray);
void		cb_init_step_x(t_cub3d *cub, t_ray *ray);
void		cb_init_step_y(t_cub3d *cub, t_ray *ray);
void		cb_perform_dda(t_cub3d *cub, t_ray *ray);
void		cb_calc_wall_dist(t_ray *ray);
void		cb_check_map_bounds(t_cub3d *cub, t_ray *ray, int *hit);

// Keys
void		cb_key_hook(mlx_key_data_t keydata, void *param);

// Player
void		cb_init_player(t_cub3d *cub);
void		cb_init_player_pos(t_cub3d *cub, char c, int x, int y);
void		cb_move_forward(t_cub3d *cub);
void		cb_move_backward(t_cub3d *cub);
void		cb_move_left(t_cub3d *cub);
void		cb_move_right(t_cub3d *cub);
void		cb_rotate_left(t_cub3d *cub);
void		cb_rotate_right(t_cub3d *cub);

//Map validation
int			cb_validate_map_borders_vertical(t_map *map);
int			cb_validate_map_borders_horizontal(t_map *map);
int			cb_validate_map_borders(t_map *map);
int			cb_validate_player_count(t_map *map);
int			cb_validate_no_empty_lines(t_map *map);
int			cb_validate_allowed_chars(t_map *map);
int			cb_is_open_to_outside(t_map *map, int y, int x);
int			cb_validate_no_open_spaces(t_map *map);
int			cb_validate_map_all(t_map *map);

// Weapon
void		cb_init_weapon(t_weapon *weapon);
int			cb_load_weapon_frames(t_weapon *weapon);
void		cb_free_weapon(t_weapon *weapon);
double		cb_get_current_time(void);
void		cb_update_weapon_animation(t_cub3d *cub);
void		cb_mouse_hook(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);
void		cb_draw_weapon(t_cub3d *cub);

//Utils
void		cb_free_map_grid(t_map *map);
void		cb_mlx_cleanup(t_cub3d *cub);
char		*ft_strndup(const char *s, size_t n);

#endif
