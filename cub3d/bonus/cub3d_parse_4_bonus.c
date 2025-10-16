/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:51:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/09 14:51:49 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Auxiliary of check_lines_allowed_chars.
// Checks if a line is part of the map section.
int	cb_check_map_sect(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// Auxiliary of check_lines_allowed_chars.
// Validates and displays an error if a map line contains invalid characters.
int	cb_check_line_allowed_chars(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			continue ;
		}
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
		{
			printf("Error: Character not allowed \n");
			return (0);
		}
		i++;
	}
	return (1);
}

// Auxiliary of check_map_allowed_chars.
// Validates whether the map section contains valid characters.
int	cb_check_lines_allowed_chars(int fd)
{
	char	*line;
	int		in_map_section;

	in_map_section = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!in_map_section && cb_check_map_sect(line) && ft_strlen(line) > 1)
			in_map_section = 1;
		if (in_map_section)
		{
			if (!cb_check_line_allowed_chars(line))
			{
				free(line);
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

// Open file and verify that the map section only contains permitted characters.
int	cb_check_map_allowed_chars(const char *filename)
{
	int	fd;
	int	result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: the .cub file could not be opened\n");
		return (1);
	}
	result = cb_check_lines_allowed_chars(fd);
	close(fd);
	return (result);
}
