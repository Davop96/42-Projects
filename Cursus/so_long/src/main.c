/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/30 11:50:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*player_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*collectible_image;
	mlx_image_t		*exit_image;
	char			**map;
	int				map_width;
	int				map_height;
}	t_game;

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
