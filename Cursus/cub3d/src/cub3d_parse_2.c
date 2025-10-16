/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:08:14 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/01 13:34:29 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Auxiliary of validate_map_single_line.
// Checks if a line is part of the map section.
int	cb_check_is_map_line(const char *line, int in_map_section)
{
	int	i;

	i = 0;
	if (in_map_section && line[0] == '\0')
	{
		printf("Error: Empty line in the map section of the .cub file.\n");
		return (-1);
	}
	if (line[0] == '\0')
		return (0);
	if (!in_map_section)
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			i++;
		}
		return (1);
	}
	return (1);
}

// Auxiliary of cb_check_map_empty_lines.
// Validates each individual line, and marks if it is the start of the map.
int	cb_validate_map_single_line(char *line, int *in_map_section)
{
	size_t	len;
	int		map_status;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	map_status = cb_check_is_map_line(line, *in_map_section);
	if (!(*in_map_section) && map_status == 1)
		*in_map_section = 1;
	if (map_status == -1)
		return (1);
	return (0);
}

// Check that there are no empty lines in the map section.
int	cb_check_map_empty_lines(const char *filename)
{
	int		fd;
	int		in_map_section;
	char	*line;

	in_map_section = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: the .cub file could not be opened\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (cb_validate_map_single_line(line, &in_map_section))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
