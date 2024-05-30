/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/30 17:07:47 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "MLX42.h"

#define TILE_SIZE 32

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	populate_map(int fd, char **map, int height)
{
	int		i;
	char	*line;

	i = 0;
	*line = get_next_map_line(fd);
	while (i < height && line != NULL)
	{
		ft_strcpy(map[i], line);
		free(line);
		i++;
		line = get_next_map_line(fd);
	}
}

char	**read_map(const char *filename, int *width, int *height)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	*width = determine_map_dimensions(fd, width, height);
	**map = allocate_map_memory(*width, *height);
	populate_map(fd, map, *height);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	game.map = read_map(argv[1], &game.map_width, &game.map_height);
	if (!game.map)
	{
		ft_printf("Error: Failed to read map\n");
		return (1);
	}
	if (initialize_mlx(&game, game.map_width, game.map_height, TILE_SIZE))
	{
		free_map_memory(game.map, game.map_height);
		return (1);
	}
	load_textures(&game);
	create_images(&game);
	mlx_loop(game.mlx);
	free_map_memory(game.map, game.map_height);
	return (0);
}






